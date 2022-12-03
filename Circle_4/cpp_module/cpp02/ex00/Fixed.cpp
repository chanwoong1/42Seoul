/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:57:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/03 19:22:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : number(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& operator=(const Fixed& fixed) {
  if (*this != &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->number;
}

void Fixed::setRawBits(int const raw) {
  this->number = raw;
}