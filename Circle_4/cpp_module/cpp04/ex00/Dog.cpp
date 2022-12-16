/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:24:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 18:13:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  std::cout << std::setw(15) << "[Dog] " << "create!!" << std::endl;
}

Dog::Dog(const Dog& dog) {
  this->_type = dog.getType();
  std::cout << std::setw(15) << "[Dog] " << "copy!!" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
  if (this != &dog)
    this->_type = dog.getType();
  return *this;
}

Dog::~Dog() {
  std::cout << std::setw(15) << "[Dog] " << "delete!!" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof! Woof!" << std::endl;
}
