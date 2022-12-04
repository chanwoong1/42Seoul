/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:54:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/04 23:09:48 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _type(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack(void) const {
  std::cout << this->_name << " attacks with his " 
            << this->_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon *type) {
  this->_type = type;
}