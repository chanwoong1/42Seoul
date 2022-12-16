/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:33:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 18:41:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
* A default constructor
*/
WrongCat::WrongCat()
  : WrongAnimal() {
  this->_type = "WrongAnimal";
  std::cout << std::setw(15) << "[WrongCat] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
WrongCat::WrongCat(const WrongCat& ref) {
  this->_type = ref.getType();
  std::cout << std::setw(15) << "[WrongCat] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
WrongCat&	WrongCat::operator=(const WrongCat& ref) {
  std::cout << std::setw(15) << "[WrongCat] " << "operator=!!" << std::endl;
  if (this != &ref) {
    this->_type = ref.getType();
  }
  return *this;
}

/*
* A destructor
*/
WrongCat::~WrongCat() {
  std::cout << std::setw(15) << "[WrongCat] " << "delete!!" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat sound ~~~" << std::endl;
}