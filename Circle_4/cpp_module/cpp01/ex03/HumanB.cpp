/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:54:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 17:58:07 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
  this->_name = name;
}

HumanB::~HumanB() {
}

void HumanB::attack(void) {
  std::cout << this->_name << " attacks with his " 
            << this->_type.getType() << std::endl;
}

void HumanB::setWeapon(Weapon type) {
  this->_type = type;
}