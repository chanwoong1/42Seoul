/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:01:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 04:26:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
* A default constructor
*/
Character::Character()
  : _name("") {
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << std::setw(15) << "[Character] " << "create!!" << std::endl;
}

Character::Character(std::string name)
  : _name(name) {
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << std::setw(15) << "[Character] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
Character::Character(const Character& ref) {
  this->_name = ref._name;
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i])
      delete this->_inventory[i];
    this->_inventory[i] = NULL;
    if (ref._inventory[i])
      this->_inventory[i] = ref._inventory[i];
  }
  std::cout << std::setw(15) << "[Character] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
Character&	Character::operator=(const Character& ref) {
  std::cout << std::setw(15) << "[Character] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
    this->_name = ref._name;
    for (int i = 0; i < 4; i++) {
      if (this->_inventory[i])
        delete this->_inventory[i];
      this->_inventory[i] = NULL;
      if (ref._inventory[i])
        this->_inventory[i] = ref._inventory[i];
    }
  }
  return *this;
}

/*
* A destructor
*/
Character::~Character() {
  std::cout << std::setw(15) << "[Character] " << "delete!!" << std::endl;
}

std::string const &Character::getName() {
  return this->_name;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m->clone();
      std::cout << std::setw(15) << "[Character] " << this->_inventory[i]->getType() << " equip success!!" << std::endl;
      return ;
    }
  }
  std::cout << std::setw(15) << "[Character] " << "equip failure!!" << std::endl;
}

void Character::unequip(int idx) {
  if (this->_inventory[idx])
    delete this->_inventory[idx];
  this->_inventory[idx] = NULL;
  std::cout << std::setw(15) << "[Character] " << "unequip success!!" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3) {
    std::cout << std::setw(15) << "[Character] " << "use - out of range" << std::endl;
    return ;
  }
  if (this->_inventory[idx] == NULL) {
    std::cout << std::setw(15) << "[Character] " << "use inventory[" << idx << "] is NULL!!" << std::endl;
    return ;
  }
  this->_inventory[idx]->use(target);
}
