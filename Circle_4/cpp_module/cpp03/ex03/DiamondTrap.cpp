/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:31:11 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/19 12:06:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
* A default constructor
  ? 여기서 energyPoints를 50을 주는 이유는 ClapTrap -> ScavTrap -> FragTrap이라는 상속 과정으로 인해 결국 ClapTrap의 변수는 FragTrap에 의해 바뀌게 되어 ScavTrap을 통해 변수를 가져와도 FragTrap으로 변경한 값이 불러오게 된다.
  ! 따라서 _energyPoints 변수에 직접 50을 넣어주는것으로 결정하고, 다이아몬드 상속이 이런 불편함 때문에 권장하지 않는 상속방법이라는 것을 알고 넘어가기로 결정했다.
*/
DiamondTrap::DiamondTrap()
  : ClapTrap("DiamondTrap_clap_name") {
  std::cout << "DiamondTrap default constructor is called." << std::endl;
  this->_name = "DiamondTrap";
  // this->_energyPoints = ScavTrap::_energyPoints;
  this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name + "_clap_name") {
  std::cout << "DiamondTrap " << name << " is called." << std::endl;
  this->_name = name;
  this->_energyPoints = 50;
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

void DiamondTrap::printStatus(void) {
  std::cout << "Name: " << this->_name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
  std::cout << "Hit points: " << this->_hitPoints << std::endl;
  std::cout << "Energy points: " << this->_energyPoints << std::endl;
  std::cout << "Attack damage: " << this->_attackDamage << std::endl;
}
