/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:57:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/11 21:43:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
* A default constructor
*/
Fixed::Fixed() : number(0) {
  std::cout << "Default constructor called" << std::endl;
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
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) {
    this->number = fixed.getRawBits();
  }
  return (*this);
}

/*
* A destructor
*/
Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

/*
* A member function int getRawBits( void ) const;
  ! that returns the raw value of the fixed-point value.
*/
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->number;
}

/*
* A member function void setRawBits( int const raw );
  ! that sets the raw value of the fixed-point number.
*/
void Fixed::setRawBits(int const raw) {
  this->number = raw;
}
