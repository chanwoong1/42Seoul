/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:01:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/05 20:34:05 by chanwjeo         ###   ########.fr       */
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

ClapTrap::ClapTrap( const ClapTrap& clapTrap ) {
  std::cout << "Copy constructor called" << std::endl;
  *this = clapTrap;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& clapTrap ) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &clapTrap) {
    this->number = fixed.getRawBits();
  }
  return (*this);
}




// void attack( const std::string& target );
// void takeDamage( unsigned int amount );
// void beRepaired( unsigned int amount );