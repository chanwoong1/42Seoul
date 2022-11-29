/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:46:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 09:02:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon *type) : _name(name), _type(*type) {
}

HumanA::~HumanA() {
}

void HumanA::attack(void) const {
  std::cout << this->_name << " attacks with his " 
            << this->_type.getType() << std::endl;
}
