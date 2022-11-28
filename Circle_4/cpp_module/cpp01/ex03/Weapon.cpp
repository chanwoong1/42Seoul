/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:38:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 20:01:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) {
  this->_type = type;
}

Weapon::~Weapon() {
}

void Weapon::setType(std::string type) {
  this->_type = type;
}

std::string Weapon::getType(void) {
  return this->_type;
}
