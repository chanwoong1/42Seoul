/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:45:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/29 12:40:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
* A default constructor
*/
Cure::Cure() : AMateria("cure") {
  std::cout << std::setw(15) << "[Cure] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
Cure::Cure(const Cure& ref) : AMateria(ref.getType()) {
  std::cout << std::setw(15) << "[Cure] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
Cure&	Cure::operator=(const Cure& ref) {
  std::cout << std::setw(15) << "[Cure] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
    this->_type = ref.getType();
  }
  return *this;
}

/*
* A destructor
*/
Cure::~Cure() {
  std::cout << std::setw(15) << "[Cure] " << "delete!!" << std::endl;
}

AMateria* Cure::clone() const {
  return (new Cure());
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}