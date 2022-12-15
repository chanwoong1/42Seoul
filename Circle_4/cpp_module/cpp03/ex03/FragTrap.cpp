/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:24:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/15 11:31:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
* A default constructor
*/
FragTrap::FragTrap()
  : ClapTrap("FragTrap") {
  std::cout << "FragTrap FragTrap is created." << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
  : ClapTrap(name) {
  std::cout << "FragTrap " << name << " is created." << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
}

/*
* A copy constructor
*/
FragTrap::FragTrap(const FragTrap& fragTrap) {
  std::cout << "FragTrap copy constructor called." << std::endl;
  this->_name = fragTrap.getName();
  this->_hitPoints = fragTrap.getHitPoints();
  this->_energyPoints = fragTrap.getEnergyPoints();
  this->_attackDamage = fragTrap.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
  std::cout << "FragTrap operator= " << fragTrap.getName() << " called." << std::endl;
  if (this != &fragTrap) {
    this->_name = fragTrap.getName();
    this->_hitPoints = fragTrap.getHitPoints();
    this->_energyPoints = fragTrap.getEnergyPoints();
    this->_attackDamage = fragTrap.getAttackDamage();
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->_name << " destructor called." << std::endl;
}

/*
* FragTrap will also have its own special capacity
*/
void FragTrap::highFivesGuys() {
  if (this->_hitPoints == 0 || this->_energyPoints == 0) {
    (this->_energyPoints == 0) ?
      std::cout << "FragTrap is not enough energy." << std::endl :
      std::cout << "FragTrap " << this->_name << "'s HP is 0. Please repair !" << std::endl; 
    return ;
  }
  std::cout << "FragTrap " << this->_name << " high five!" << std::endl;
  this->_energyPoints--;
}
