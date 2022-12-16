/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:23:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 23:46:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
* A constructor
  ! Constructor of each class must display specific messages.
*/
Animal::Animal()
  : _type("Animal") {
  std::cout << std::setw(15) << "[Animal] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
Animal::Animal(const Animal& animal)
  : _type(animal.getType()) {
  std::cout << std::setw(15) << "[Animal] " << "copy!!" << std::endl;
}

/*
* A copy assignment operator
*/
Animal& Animal::operator=(const Animal& animal) {
  if (this != &animal) {
    this->_type = animal._type;
  }
  return (*this);
}

/*
* A destructor
  ! Destructor of each class must display specific messages.
*/
Animal::~Animal() {
  std::cout << std::setw(15) << "[Animal] " << "delete!!" << std::endl;
}

std::string Animal::getType() const {
  return this->_type;
}

std::ostream& operator<<(std::ostream& ofs, const Animal& animal) {
  return ofs << animal.getType();
}
