/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:57:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/11 22:01:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& o, const Fixed& f) {
  return o << f.toFloat();
}

int Fixed::getRawBits(void) const {
  return this->fixedPoint;
}

void Fixed::setRawBits(const int raw) {
  this->fixedPoint = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->fixedPoint) / (1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const {
  return this->fixedPoint >> Fixed::fractionalBits;
}

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignation operator called" << std::endl;
  if (this != &f)
    this->fixedPoint = f.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed& f) {
  return this->fixedPoint > f.fixedPoint;
}

bool Fixed::operator<(const Fixed& f) {
  return this->fixedPoint < f.fixedPoint;
}

bool Fixed::operator>=(const Fixed& f) {
  return this->fixedPoint >= f.fixedPoint;
}

bool Fixed::operator<=(const Fixed& f) {
  return this->fixedPoint <= f.fixedPoint;
}

bool Fixed::operator==(const Fixed& f) {
  return this->fixedPoint == f.fixedPoint;
}

bool Fixed::operator!=(const Fixed& f) {
  return this->fixedPoint != f.fixedPoint;
}

Fixed::Fixed(void)
  : fixedPoint(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int v)
  : fixedPoint(v << Fixed::fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float v)
  : fixedPoint(static_cast<int>(roundf(v * (1 << Fixed::fractionalBits)))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

/*
* The 4 arithmetic operators (+, -, *, /)
*/


/*
* The 4 increment / decrement operators (++a, a++, --a, a--)
*/


/*
* A static member function min
  ! that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
*/


/*
* A static member function min
  ! that takes as parameters two references to constant fixed-point numvers, and returns a reference to the smallest one.
*/


/*
* A static member function max
  ! that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
*/


/*
* A static member function max
  ! that takes as parameters two references to constant fixed-point numvers, and returns a reference to the greatest one.
*/