/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:39:17 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 05:30:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
* A default constructor
*/
Ice::Ice() {
  this->_type = "ice";
  std::cout << std::setw(15) << "[Ice] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
Ice::Ice(const Ice& ref) {
  this->_type = ref.getType();
  std::cout << std::setw(15) << "[Ice] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
Ice&	Ice::operator=(const Ice& ref) {
  std::cout << std::setw(15) << "[Ice] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
    this->_type = ref.getType();
  }
  return *this;
}

/*
* A destructor
*/
Ice::~Ice() {
  std::cout << std::setw(15) << "[Ice] " << "delete!!" << std::endl;
}

AMateria* Ice::clone() const {
  return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}