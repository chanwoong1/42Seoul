/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:57:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/12 10:34:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
* A default constructor
! A constructor that takes a constant integer as a parameter.
! A constructor that takes a constant floating-point number as a parameter.
! It converts it to the corresponding fixed-point value. the fractional bits value is initialized to 8 like in ex00.
*/
Fixed::Fixed(void)
  : fixedPoint(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
  : fixedPoint(value << Fixed::fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
  : fixedPoint(static_cast<int>(roundf(value * (1 << Fixed::fractionalBits)))) {
  std::cout << "Float constructor called" << std::endl;
}

/*
* A copy constructor
*/
Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

/*
* A copy assignment operator overload
*/
Fixed& Fixed::operator=(const Fixed& fixed) {
  std::cout << "Copy assignation operator called" << std::endl;
  if (this != &fixed)
    this->fixedPoint = fixed.getRawBits();
  return *this;
}

/*
* A destructor
*/
Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

/*
* A member function int getRawBits( void ) const;
  ! that returns the raw value of the fixed-point value.
*/
int Fixed::getRawBits(void) const {
  return this->fixedPoint;
}

/*
* A member function void setRawBits( int const raw );
  ! that sets the raw value of the fixed-point number.
*/
void Fixed::setRawBits(const int raw) {
  this->fixedPoint = raw;
}

/*
* A member function float toFloat( void ) const;
  ! that converts the fixed-point value to a floating-point value.
*/
float Fixed::toFloat(void) const {
  return static_cast<float>(this->fixedPoint) / (1 << Fixed::fractionalBits);
}

/*
* A member function int toInt( void ) const;
  ! that converts the fixed-point value to an integer value.
*/
int Fixed::toInt(void) const {
  return this->fixedPoint >> Fixed::fractionalBits;
}

/*
* Add the following function to the Fixed class files 
* An overload of the insertion ( << ) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
*/
std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed) {
  return ofs << fixed.toFloat();
}
