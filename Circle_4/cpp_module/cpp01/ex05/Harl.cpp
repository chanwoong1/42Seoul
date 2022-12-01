/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:34:40 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 15:53:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::complain(std::string level) {
  void (Harl::*f[4])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
  };
  std::string findComplain("DEBUG,INFO,WARNING,ERROR");

  if (level.find(",") >= 0 && level.find(",") <= findComplain.length()) {
    std::cout << "It's not my complain." << std::endl;
    return ;
  }
  
  switch (findComplain.find(level)) {
    case 0:
      (this->*f[0])();
      break;
    case 6:
      (this->*f[1])();
      break;
    case 11:
      (this->*f[2])();
      break;
    case 19:
      (this->*f[3])();
      break;
    default:
      std::cout << "It's not my complain." << std::endl;
      break;
  }
}

void Harl::debug() {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
