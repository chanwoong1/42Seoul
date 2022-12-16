/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:24:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 11:12:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  std::cout << "Cat " << this->_type << " constructor is called." << std::endl;
}

Cat::Cat(const Cat& cat) {
  this->_type = cat.getType();
}

Cat& Cat::operator=(const Cat& cat) {
  if (this != &cat)
    this->_type = cat.getType();
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat " << this->_type << " destructor is called." << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!" << std::endl;
}
