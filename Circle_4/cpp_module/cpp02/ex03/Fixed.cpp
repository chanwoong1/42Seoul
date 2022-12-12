/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:57:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/12 17:20:02 by chanwjeo         ###   ########.fr       */
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
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
  : fixedPoint(value << Fixed::fractionalBits) {
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
  : fixedPoint(static_cast<int>(roundf(value * (1 << Fixed::fractionalBits)))) {
  // std::cout << "Float constructor called" << std::endl;
}

/*
* A copy constructor
*/
Fixed::Fixed(const Fixed& fixed) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

/*
* A copy assignment operator overload
*/
Fixed& Fixed::operator=(const Fixed& fixed) {
  // std::cout << "Copy assignation operator called" << std::endl;
  if (this != &fixed)
    this->fixedPoint = fixed.getRawBits();
  return *this;
}

/*
* A destructor
*/
Fixed::~Fixed(void) {
  // std::cout << "Destructor called" << std::endl;
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
  * The 6 comparison operations (>, <, >=, <=, ==, !=)
*/
bool operator>(const Fixed& fixed1, const Fixed& fixed2) {
  return fixed1.getRawBits() > fixed2.getRawBits();
}

bool operator<(const Fixed& fixed1, const Fixed& fixed2) {
  return fixed1.getRawBits() < fixed2.getRawBits();
}

bool operator>=(const Fixed& fixed1, const Fixed& fixed2) {
  return fixed1.getRawBits() >= fixed2.getRawBits();
}

bool operator<=(const Fixed& fixed1, const Fixed& fixed2) {
  return fixed1.getRawBits() <= fixed2.getRawBits();
}

bool operator==(const Fixed& fixed1, const Fixed& fixed2) {
  return fixed1.getRawBits() == fixed2.getRawBits();
}

bool operator!=(const Fixed& fixed1, const Fixed& fixed2) {
  return fixed1.getRawBits() != fixed2.getRawBits();
}

/*
* The 4 arithmetic operators (+, -, *, /)
*/
Fixed operator+(const Fixed& fixed1, const Fixed& fixed2) {
  return Fixed(fixed1.toFloat() + fixed2.toFloat());
}

Fixed operator-(const Fixed& fixed1, const Fixed& fixed2) {
  return Fixed(fixed1.toFloat() - fixed2.toFloat());
}

Fixed operator*(const Fixed& fixed1, const Fixed& fixed2) {
  return Fixed(fixed1.toFloat() * fixed2.toFloat());
}

Fixed operator/(const Fixed& fixed1, const Fixed& fixed2) {
  return Fixed(fixed1.toFloat() / fixed2.toFloat());
}

/*
* The 4 increment / decrement operators (++a, a++, --a, a--)
*/
Fixed &Fixed::operator++(void) {
  this->fixedPoint++;
  return *this;
}

Fixed &Fixed::operator--(void) {
  this->fixedPoint--;
  return *this;
}

const Fixed Fixed::operator++(int) {
  const Fixed tmp(*this);

  this->fixedPoint++;
  return tmp;
}

const Fixed Fixed::operator--(int) {
  const Fixed tmp(*this);

  this->fixedPoint--;
  return tmp;
}

/*
* A static member function min
  ! that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
*/
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed1 : fixed2;
}

/*
* A static member function min
  ! that takes as parameters two references to constant fixed-point numvers, and returns a reference to the smallest one.
*/
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed1 : fixed2;
}

/*
* A static member function max
  ! that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
*/
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed2 : fixed1;
}

/*
* A static member function max
  ! that takes as parameters two references to constant fixed-point numvers, and returns a reference to the greatest one.
*/
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed2 : fixed1;
}


std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed) {
  return ofs << fixed.toFloat();
}