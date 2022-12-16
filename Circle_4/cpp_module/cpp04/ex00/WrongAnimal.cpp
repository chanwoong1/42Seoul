/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:39:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 11:52:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
  : _type("WrongAnimal") {
  std::cout << "WrongAnimal constructor is called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) {
  std::cout << "WrongAnimal copy constructor is called." << std::endl;
  this->_type = wrongAnimal.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal) {
  if (this != &wrongAnimal)
    this->_type = wrongAnimal.getType();
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor is called." << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound ~~~" << std::endl;
}

std::string WrongAnimal::getType() const {
  return this->_type;
}

std::ostream& operator<<(std::ostream& ofs, const WrongAnimal& wrongAnimal) {
  return ofs << wrongAnimal.getType();
}
