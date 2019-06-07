/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"
#include "velocity.h"
#include <time.h>
#include <stdlib.h>

/*********************************************
 * Constructor
 * Initializes the game
 *********************************************/
Game :: Game(Point tl, Point br) : 
topLeft(tl), bottomRight(br), ground(Ground(topLeft, bottomRight))
{
   // Set up the initial conditions of the game
   
   // Set random initial horizontal velocity between -2 and 2 pixels per frame.
   srand(time(0));
   float initialVelocity = static_cast<float>(rand() % 5 - 2);
   lander.setVelocity(Velocity(initialVelocity, 0));
   
   // Set starting lander position to the top center of the screen.
   lander.setPoint(Point(0, tl.getY()));

   // Set fuel level
   lander.setFuel(FUEL);

   // The lander must be aware of the ground
   lander.setGround(ground);
}

/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (lander.isAlive() && !lander.isLanded())
   {
      // advance the lander
      lander.applyGravity(GRAVITY_AMOUNT);
      lander.advance();
   
      // check for crash
      if (!ground.isAboveGround(lander.getPoint()))
      {
         lander.setAlive(false);
      }
   
      // check for just landed
      if (justLanded())
      {
         lander.setLanded(true);
      }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (lander.isAlive() && !lander.isLanded())
   {
   
      if (ui.isDown())
      {
         lander.applyThrustBottom();
      }
      
      if (ui.isLeft())
      {
         lander.applyThrustLeft();
      }
      
      if (ui.isRight())
      {
         lander.applyThrustRight();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   lander.draw();

   if (lander.isLanded())
   {
      drawText(Point(), "You have successfully landed!");
   }
   
   if (!lander.isAlive())
   {
      drawText(Point(), "You have crashed!");
   }
   
   if (lander.canThrust())
   {
      drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
   }
   
   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 5);
   fuelLocation.setY(topLeft.getY() - 5);
   
   drawNumber(fuelLocation, lander.getFuel());

   // draw ground
   ground.draw();
}

