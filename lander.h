/***********************************************************************
 * Header File:
 *    LANDER : A class representing a lunar lander
 * Author:
 *    Drazen Lucic
 * Summary:
 *    Everything we need to know about a lunar lander including
 *    the location, velocity, fuel level, and status (landed, alive).
 *    Also includes methods to draw the lander and apply the thrust.
 ************************************************************************/


#ifndef LANDER_H
#define LANDER_H

#include <iostream>
#include "point.h"
#include "ground.h"
#include "velocity.h"

#define UPWARD_THRUST_AMOUNT 0.3
#define UPWARD_THRUST_FUEL 3
#define SIDE_THRUST_AMOUNT 0.1
#define SIDE_THRUST_FUEL 1

/*********************************************
 * LANDER
 * A fast but fragile vehicle that only skilled pilots can control.  
 *********************************************/
class Lander
{
public:
   // constructors
   Lander() {}

   // getters
   Point getPoint() const { return m_point; }
   Velocity getVelocity() const { return m_velocity; }
   int getFuel() const { return m_fuel; }

   // setters
   void setPoint(const Point & point) { m_point = point; }
   void setVelocity(const Velocity & velocity) { m_velocity = velocity; }
   void setFuel(int fuel) { m_fuel = fuel; }
   void setAlive(bool alive) { m_alive = alive; }
   void setLanded(bool landed) { m_landed = landed; }
   void setGround(const Ground & ground) { m_ground = &ground; }

   // Returns true if the thrusters can be activaed
   bool canThrust() const;

   // Returns true while the lander is alive
   bool isAlive() const;

   // Returns true when the lander lands on the platform.
   bool isLanded() const;

   // Applies gravity on the lander effectively pulling it down
   void applyGravity(float gravity);

   // Activates lander's left thruster, which pushes the lander to the right.
   void applyThrustLeft();

   // Activates lander's right thruster, which pushes the lander to the left.
   void applyThrustRight();

   // Activates lander's bottom thruster, which slows lander's descent.
   void applyThrustBottom();

   // Advances the lander to a new position.
   void advance();

   // Draws the lander on the screen.
   void draw() const;

private:
   Point m_point;         // Lander's position
   Velocity m_velocity;   // Lander's velocity
   int m_fuel;            // Lander's fuel quantity
   bool m_alive;          // A flag indicating if the lander is alive
   bool m_landed;         // A flag indicating if the lander has landed

   const Ground * m_ground; // A ground object is used to access isAboveGround() method
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Lander & lander);
std::istream & operator >> (std::istream & in,        Lander & lander);

#endif // LANDER_H
