/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:31:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/15 10:35:07 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
* A default constructor
*/
DiamondTrap::DiamondTrap()
  : ClapTrap(ClapTrap::_name + "_clap_name") {
  std::cout << "DiamondTrap default constructor is called." << std::endl;
  this->_name = "DiamondTrap";
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;  
}

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name + "_clap_name") {
  std::cout << "DiamondTrap " << name << " is called." << std::endl;
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
}

/*
* A copy constructor
*/
DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
  std::cout << "DiamondTrap copy constructor is called." << std::endl;
  this->_name = diamondTrap.getName();
  this->_hitPoints = diamondTrap.getHitPoints();
  this->_energyPoints = diamondTrap.getEnergyPoints();
  this->_attackDamage = diamondTrap.getAttackDamage();
}

/*
* A copy assignment operator
*/
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
  std::cout << "DiamondTrap copy assignment operator is called." << std::endl;
  if (this != &diamondTrap) {
    this->_name = diamondTrap.getName();
    this->_hitPoints = diamondTrap.getHitPoints();
    this->_energyPoints = diamondTrap.getEnergyPoints();
    this->_attackDamage = diamondTrap.getAttackDamage();
  }
  return *this;
}

/*
* A destructor
*/
DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << this->_name << " destructor is called." << std::endl;
}

/*
TODO: DiamondTrap will have its own special capacity
  ! This member function will display both its name and its ClapTrap name.
*/
void DiamondTrap::wheAmI(void) {
  std::cout << "My name is " << this->_name << "." << std::endl;
  std::cout << "My ClapTrap name is " << ClapTrap::getName() << "." << std::endl;
}
