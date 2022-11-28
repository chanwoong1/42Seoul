/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:46:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 17:59:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon type) {
  this->_name = name;
  this->_type = type;
}

HumanA::~HumanA() {
}

void HumanA::attack(void) {
  std::cout << this->_name << " attacks with his " 
            << this->_type.getType() << std::endl;
}
