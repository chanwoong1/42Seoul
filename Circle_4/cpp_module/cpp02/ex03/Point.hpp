/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:11:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/12 18:10:35 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H_
# define POINT_H_

#include <iostream>
#include "Fixed.hpp"

class Point {
  private:
    /*
    * A Fixed const attribute x.
    * A Fixed const attribute y.
    */
    Fixed const _x;
    Fixed const _y;

  public:
    /*
    * A default constructor that initializes x and y to 0.
    */
    Point();

    /*
    * A constructor that takes as parameters two constant floating-point numbers.
      ! It initializes x and y with those parameters.
    */
    Point(const float x, const float y);
    
    /*
    * A copy constructor.
    */
    Point(const Point& point);
    
    /*
    * A copy assignment operator overload.
    */
    Point& operator=(const Point& point);
    
    /*
    * A destructor.
    */
    ~Point();
    
    /*
    * Anything else useful
    ? A member function const Fixed getX() const;
      ! It returns the raw class of the Fixed const attribute x.
    */
    const Fixed& getX() const;

    /*
    ? A member function const Fixed getY() const;
      ! It returns the raw class of the Fixed const attribute y. 
    */
    const Fixed& getY() const;
};

std::ostream& operator<<(std::ostream& ofs, const Point& point);

/*
* To conclude, implement the following function in the appropriate file
  todo  a, b, c: The vertices of our beloved triangle.
  todo  point: The point to check.
  todo  Returns: True if the point is inside the triangle. False otherwise. Thus if the point is a vertex or on edge, it will return False.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point);
Point operator-(const Point &point1, const Point &point2);
Fixed	operator*(const Point& point1, const Point& point2);
bool operator~(const Fixed& fixed);

#endif
