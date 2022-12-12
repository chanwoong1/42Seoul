/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:01 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/12 17:06:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
* A default constructor that initializes x and y to 0.
*/
Point::Point() : _x(0), _y(0) {
}

/*
* A constructor that takes as parameters two constant floating-point numbers.
  ! It initializes x and y with those parameters.
*/
Point::Point(const float x, const float y)
  : _x(x), _y(y) {
}

/*
* A copy constructor.
*/
Point::Point(const Point& point)
  : _x(point.getX()), _y(point.getY()) {
}

/*
* A copy assignment operator overload.
*/
Point& Point::operator=(const Point& point) {
  if (this != &point) {
    const_cast<Fixed&>(_x) = point.getX();
    const_cast<Fixed&>(_y) = point.getY();
  }
  return *this;
}

/*
* A destructor.
*/
Point::~Point() {
}

/*
* Anything else useful
? A member function const Fixed getX() const;
  ! It returns the raw class of the Fixed const attribute x.
*/
const Fixed& Point::getX() const {
  return this->_x;
}

/*
? A member function const Fixed getY() const;
  ! It returns the raw class of the Fixed const attribute y. 
*/
const Fixed& Point::getY() const {
  return this->_y;
}


std::ostream& operator<<(std::ostream& ofs, const Point& point) {
  return ofs << "( " << point.getX().toFloat() << ", " << point.getY().toFloat() << " )";
}
