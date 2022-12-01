/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:10:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 13:13:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
}

Zombie::Zombie(std::string name) {
  this->_name = name;
}

Zombie::~Zombie() {
  std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  this->_name = name;
}