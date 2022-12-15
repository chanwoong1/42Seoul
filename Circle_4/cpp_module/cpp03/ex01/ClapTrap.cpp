/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:01:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/15 10:55:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
* A default constructor
* param: std::string name
TODO: Initialize private parameters [ _hitPoints(10), _energyPoints(10), _attackDamage(0) ]
! The constructor must also display a message.
*/
ClapTrap::ClapTrap()
  : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap ClapTrap is created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
  : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << name << " is created." << std::endl;
}

/*
* A copy constructor
*/
ClapTrap::ClapTrap( const ClapTrap& clapTrap )
  : _name(clapTrap.getName()), _hitPoints(clapTrap.getHitPoints()), _energyPoints(clapTrap.getEnergyPoints()), _attackDamage(clapTrap.getAttackDamage()) {
  std::cout << "ClapTrap Copy constructor called" << std::endl;
}

/*
* A copy assignment operator overload
*/
ClapTrap& ClapTrap::operator=( const ClapTrap& clapTrap ) {
  std::cout << "ClapTrap Copy assignment operator called" << std::endl;
  if (this != &clapTrap) {
    _name = clapTrap.getName();
    _hitPoints = clapTrap.getHitPoints();
    _energyPoints = clapTrap.getEnergyPoints();
    _attackDamage = clapTrap.getAttackDamage();
  }
  return (*this);
}

/*
* A destructor
! The destructor must also display a message.
*/
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->_name << " is destructed." << std::endl; 
}

/*
TODO: Add the following public member functions so the ClapTrap looks more realistic
! When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
! When ClapTrap repairs itself, it gets <amount> hit points back.
! Attacking and repairing cost 1 energy point each.
! Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
*/
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

/*
TODO: Display a message to describe what happens.
* example: ClapTrap <name> attacks <target>, causing <damage> points of damage!
*/
void ClapTrap::attack( const std::string& target ) {
  if (this->_energyPoints == 0 || this->_hitPoints == 0) {
    (this->_energyPoints == 0) ?
      std::cout << "ClapTrap is not enough energy." << std::endl :
      std::cout << this->_name << "'s HP is 0. Please repair !" << std::endl; 
    return ;
  }

  std::cout << "ClapTrap " << this->_name << " attacks "
    << target << ", causing " << this->_attackDamage 
    << " points of damage!" << std::endl;
  this->_energyPoints--; 
}

void ClapTrap::takeDamage( unsigned int amount ) {
  std::cout << this->_name << " is attacked by " << amount << " points."
  << std::endl;
  this->_hitPoints -= amount;
  if (this->_hitPoints <= 0) {
    std::cout << this->_name << "'s HP is 0. Please repair !" << std::endl;
    this->_hitPoints = 0;
  }
}

void ClapTrap::beRepaired( unsigned int amount ) {
  if (this->_energyPoints == 0) {
      std::cout << "ClapTrap is not enough energy." << std::endl; 
    return ;
  }
  
  std::cout << this->_name << " has repaired " << amount << " points." << std::endl;
  this->_hitPoints += amount;
  this->_energyPoints--;
}
