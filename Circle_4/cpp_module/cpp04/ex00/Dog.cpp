/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:24:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 10:55:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  std::cout << "Dog " << this->_type << " constructor is called." << std::endl;
}

Dog::Dog(const Dog& dog) {
  this->_type = dog.getType();
}

Dog& Dog::operator=(const Dog& dog) {
  if (this != &dog)
    this->_type = dog.getType();
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog " << this->_type << " destructor is called." << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof! Woof!" << std::endl;
}
