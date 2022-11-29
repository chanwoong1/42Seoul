/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:38:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 08:57:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(const std::string &type) : _type(type){
}

Weapon::~Weapon() {
}

void Weapon::setType(const std::string &type) {
  this->_type = type;
}

const std::string &Weapon::getType(void) const {
  return this->_type;
}
