/***********************************************************************
 * Header File:
 *    Velocity : A class representing lunar lander's velocity
 * Author:
 *    Drazen Lucic
 * Summary:
 *    Everything we need to know about a lunar lander including
 *    the location, velocity, fuel level, and status (landed, alive).
 *    Also includes methods to draw the lander and apply the thrust.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

/*********************************************
 * VELOCITY
 * 
 *********************************************/

class Velocity
{
public:
   // constructors
   Velocity() {}
   Velocity(float dx, float dy) { 
      setDx(dx);
      setDy(dy);
   }

   // getters
   float getDx() const { return m_dx; }
   float getDy() const { return m_dy; }

   // setters
   void setDx(float dx) { m_dx = dx; }
   void setDy(float dy) { m_dx = dy; }
private:
   float m_dx;    // Horizontal velocity component
   float m_dy;    // Vertical velocity component
};

#endif // VELOCITY_H