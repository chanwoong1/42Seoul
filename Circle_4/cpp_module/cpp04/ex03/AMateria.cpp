/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:49:08 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 03:25:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
* A default constructor
*/
AMateria::AMateria()
  : _type("") {
  std::cout << std::setw(15) << "[AMateria] " << "create!!" << std::endl;
}

AMateria::AMateria(std::string const& type)
  : _type(type) {
  std::cout << std::setw(15) << "[AMateria] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
AMateria::AMateria(const AMateria& ref)
  : _type(ref.getType()) {
  std::cout << std::setw(15) << "[AMateria] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
AMateria&	AMateria::operator=(const AMateria& ref) {
  std::cout << std::setw(15) << "[AMateria] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
    this->_type = ref.getType();
  }
  return *this;
}

/*
* A destructor
*/
AMateria::~AMateria() {
  std::cout << std::setw(15) << "[AMateria] " << "delete!!" << std::endl;
}

std::string const& AMateria::getType() const {
  return this->_type;
}

void AMateria::use(ICharacter& target) {
  std::cout << "This message will not print. " << target.getName() << " is not used too." << std::endl;
}
