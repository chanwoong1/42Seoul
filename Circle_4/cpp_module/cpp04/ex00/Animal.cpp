/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:23:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 10:52:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
* A constructor
  ! Constructor of each class must display specific messages.
*/
Animal::Animal()
  : _type("Animal") {
  std::cout << "Animal " << this->_type << " constructor is called." << std::endl;
}

/*
* A copy constructor
*/
Animal::Animal(const Animal& animal) : _type(animal.getType()) {
  std::cout << "Animal " << this->_type << " copy constructor is called." << std::endl;
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
  std::cout << "Animal " << this->_type << " destructor is called." << std::endl;
}

void Animal::makeSound() const {
  std::cout << "Animal sound ~~~" << std::endl;
}

std::string Animal::getType() const {
  return this->_type;
}

std::ostream& operator<<(std::ostream& ofs, const Animal& animal) {
  return ofs << animal.getType();
}