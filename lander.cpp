/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing a lunar lander
 * Author:
 *    Drazen Lucic
 * Summary:
 *    Everything we need to know about a lunar lander including
 *    the location, velocity, fuel level, and status (landed, alive).
 *    Also includes methods to draw the lander and apply the thrust.
 ************************************************************************/

#include "lander.h"
#include "uiDraw.h"
#include "game.h"
#include <iostream>

// Returns true if the thrusters can be activaed
bool Lander::canThrust() const
{
   return isAlive() && !isLanded();
}

// Returns true while the lander is alive
bool Lander::isAlive() const
{
   return m_ground->isAboveGround(m_point);
}

// Returns true when the lander lands on the platform.
bool Lander::isLanded() const
{
   Game * game = static_cast<Game *>(Interface::p);
   return game->justLanded();
}

// Applies gravity on the lander effectively pulling it down
void Lander::applyGravity(float gravity)
{
   m_velocity.setDy(m_velocity.getDy() - gravity);
}

// Activates lander's left thruster, which pushes the lander to the right.
void Lander::applyThrustLeft()
{
   if (!canThrust()) return;
   if (m_fuel < SIDE_THRUST_FUEL) return;
   m_velocity.setDx(m_velocity.getDx() + SIDE_THRUST_AMOUNT);
   m_fuel -= SIDE_THRUST_FUEL;
}

// Activates lander's right thruster, which pushes the lander to the left.
void Lander::applyThrustRight()
{
   if (!canThrust()) return;
   if (m_fuel < SIDE_THRUST_FUEL) return;
   m_velocity.setDx(m_velocity.getDx() - SIDE_THRUST_AMOUNT);
   m_fuel -= SIDE_THRUST_FUEL;
}

// Activates lander's bottom thruster, which slows lander's descent.
void Lander::applyThrustBottom()
{
   if (!canThrust()) return;
   if (m_fuel < UPWARD_THRUST_FUEL) return;
   m_velocity.setDy(m_velocity.getDy() + UPWARD_THRUST_AMOUNT);
   m_fuel -= UPWARD_THRUST_FUEL;
}

// Advances the lander to a new position.
void Lander::advance()
{
   // m_point.setX(150);
   // m_point.setY(150);
   m_point.setX(m_point.getX() + m_velocity.getDx());
   m_point.setY(m_point.getY() + m_velocity.getDy());
}

// Draws the lander on the screen.
void Lander::draw() const
{
	drawLander(getPoint());
}