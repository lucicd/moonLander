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

// Returns true if the thrusters can be activaed
bool Lander::canThrust() const
{
   return true;
}

// Returns true while the lander is alive
bool Lander::isAlive() const
{
   return true;
}

// Returns true when the lander lands on the platform.
bool Lander::isLanded() const
{
   return false;
}

// Applies gravity on the lander effectively pulling it down
void Lander::applyGravity(float gravity)
{

}

// Activates lander's left thruster, which pushes the lander to the right.
void Lander::applyThrustLeft()
{

}

// Activates lander's right thruster, which pushes the lander to the left.
void Lander::applyThrustRight()
{

}

// Activates lander's bottom thruster, which slows lander's descent.
void Lander::applyThrustBottom()
{

}

// Advances the lander to a new position.
void Lander::advance()
{

}

// Draws the lander on the screen.
void Lander::draw() const
{
	drawLander(getPoint());
}