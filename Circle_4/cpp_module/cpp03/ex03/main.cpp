/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:04:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/15 14:51:38 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
  std::string s1 = "chanwjeo";
  std::string s2 = "chanwoong";
  std::string s3 = "Jeong";

  DiamondTrap t1(s1);
  DiamondTrap t2(s2);
  ClapTrap t3(s3);
  DiamondTrap t4;

  std::cout << std::endl;
  t1.printStatus();
  std::cout << std::endl;
  t2.printStatus();
  std::cout << std::endl;
  t4.printStatus();
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s3);
  t3.takeDamage(t1.getAttackDamage());
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s2);
  t2.takeDamage(t1.getAttackDamage());
  t2.beRepaired(t1.getAttackDamage() / 2);
  t2.beRepaired(t1.getAttackDamage() / 2);
  t2.beRepaired(t1.getAttackDamage() / 2);
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s3);
  t2.takeDamage(t1.getAttackDamage());
  t1.attack(s3);
  t2.takeDamage(t1.getAttackDamage());
  t1.attack(s3);
  t2.takeDamage(t1.getAttackDamage());
  std::cout << std::endl;

  std::cout << std::endl;
  t2.highFivesGuys();
  std::cout << std::endl;
  std::cout << std::endl;
  t1.printStatus();
  std::cout << std::endl;
  t2.printStatus();
  std::cout << std::endl;
  return 0;
}