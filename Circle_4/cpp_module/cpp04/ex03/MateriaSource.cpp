/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 05:31:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
* A default constructor
*/
MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    this->_amateria[i] = NULL;
  std::cout << std::setw(15) << "[MateriaSource] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
MateriaSource::MateriaSource(const MateriaSource& ref) {
  const AMateria* tmpAMateria;

  for (int i = 0; i < 4; i++) {
    if (this->_amateria[i])
      delete this->_amateria[i];
    
    tmpAMateria = ref.getAMateria(i);
    if (tmpAMateria)
      this->_amateria[i] = tmpAMateria->clone();
  }
  std::cout << std::setw(15) << "[MateriaSource] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
MateriaSource&	MateriaSource::operator=(const MateriaSource& ref) {
  const AMateria* tmpAMateria;
  
  std::cout << std::setw(15) << "[MateriaSource] " << "operator=!!" << std::endl;
  if (this != &ref) {
    for (int i = 0; i < 4; i++) {
      if (this->_amateria[i]) {
        delete this->_amateria[i];
        this->_amateria[i] = NULL;
      }
      
      tmpAMateria = ref.getAMateria(i);
      if (tmpAMateria)
        this->_amateria[i] = tmpAMateria->clone();
    }
  }
  return *this;
}

/*
* A destructor
*/
MateriaSource::~MateriaSource() {
  std::cout << std::setw(15) << "[MateriaSource] " << "delete!!" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (this->_amateria[i])
      delete this->_amateria[i];
    this->_amateria[i] = NULL;
  }
}

/*
* Add it if you feel necessary additional member functions.
*/
const AMateria* MateriaSource::getAMateria(int idx) const {
  return this->_amateria[idx];
}

void MateriaSource::learnMateria(AMateria* amateria) {
  for (int i = 0; i < 4; i++) {
    if (this->_amateria[i] == NULL) {
      this->_amateria[i] = amateria;
      std::cout << std::setw(15) << "[MateriaSource] " << "learnMateria success!!" << std::endl;
      return ;
    }
  }
  std::cout << std::setw(15) << "[MateriaSource] " << "learnMateria failure!!" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < 4; i++) {
    if (this->_amateria[i] && this->_amateria[i]->getType() == type) {
      std::cout << std::setw(15) << "[MateriaSource] " << "createMateria " << type << " success!!" << std::endl;

      return this->_amateria[i]->clone();
    }
  }
  std::cout << std::setw(15) << "[MateriaSource] " << "createMateria " << type << " failure!!" << std::endl;
  return NULL;
}