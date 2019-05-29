/***********************************************************************
 * Header File:
 *    Point : A class representing a lunar lander
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

/*********************************************
 * LANDER
 * A vehicle only skilled pilots can control.  
 *********************************************/
class Point
{
public:
   // constructors
   Point()            : x(0.0), y(0.0)  {}
   Point(bool check)  : x(0.0), y(0.0)  {}
   Point(float x, float y);

   // getters
   float getX()       const { return x;              }
   float getY()       const { return y;              }

   // setters
   void setX(float x);
   void setY(float y);
   void addX(float dx)      { setX(getX() + dx);     }
   void addY(float dy)      { setY(getY() + dy);     }

private:
   float x;           // horizontal position
   float y;           // vertical position
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in,        Point & pt);

#endif // LANDER_H
