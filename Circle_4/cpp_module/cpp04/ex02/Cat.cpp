/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:24:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 00:53:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << std::setw(15) << "[Cat] " << "create!!" << std::endl;
  this->_type = "Cat";
  this->brain = new Brain();
}

Cat::Cat(const Cat& cat) {
  this->_type = cat.getType();
  this->brain = new Brain(*cat.getBrain());
  std::cout << std::setw(15) << "[Cat] " << "copy!!" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
  std::cout << std::setw(15) << "[Cat] " << "operator=!!" << std::endl;
  if (this != &cat) {
    this->_type = cat.getType();
    *brain = *cat.getBrain(); 
  }
  return *this;
}

Cat::~Cat() {
  delete this->brain;
  std::cout << std::setw(15) << "[Cat] " << "delete!!" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
  return this->brain;
}