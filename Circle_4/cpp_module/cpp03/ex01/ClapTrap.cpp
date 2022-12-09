/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:01:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/09 16:22:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << name << " is created." << std::endl;
  this->_name = name;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->_name << " is destructed." << std::endl; 
}

ClapTrap::ClapTrap( const ClapTrap& clapTrap ) : _name(clapTrap.getName()), _hitPoints(clapTrap.getHitPoints()), _energyPoints(clapTrap.getEnergyPoints()), _attackDamage(clapTrap.getAttackDamage()) {
  std::cout << "Copy constructor called" << std::endl;
  *this = clapTrap;
}

std::string ClapTrap::getName(void) const {
  return _name;
}

unsigned int ClapTrap::getHitPoints(void) const {
  return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
  return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
  return _attackDamage;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& clapTrap ) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &clapTrap) {
    _name = clapTrap.getName();
    _hitPoints = clapTrap.getHitPoints();
    _energyPoints = clapTrap.getEnergyPoints();
    _attackDamage = clapTrap.getAttackDamage();
  }
  return (*this);
}

void ClapTrap::attack( const std::string& target ) {
  if (this->_energyPoints > 0 && this->_hitPoints != 0) {
    std::cout << "ClapTrap " << this->_name << " attacks "
      << target << ", causing " << this->_attackDamage 
      << " points of damage!" << std::endl;
    this->_energyPoints--;
  } else if (this->_energyPoints == 0) {
    std::cout << "Not enough energy" << std::endl;
  } else {
    std::cout << this->_name << "'s HP is 0." << std::endl;
  }
}

void ClapTrap::takeDamage( unsigned int amount ) {
  std::cout << this->_name << " is attacked by " << amount << " points."
  << std::endl;
  this->_hitPoints -= amount;
  if (this->_hitPoints == 0)
    std::cout << this->_name << "'s HP is 0." << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
  if (this->_energyPoints > 0 && this->_hitPoints != 0) {
    std::cout << this->_name << " has repaired " << amount << " points." << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints--;
  } else if (this->_energyPoints == 0) {
    std::cout << "Not enough energy" << std::endl;
  } else {
    std::cout << this->_name << "'s HP is 0." << std::endl;
  }
}