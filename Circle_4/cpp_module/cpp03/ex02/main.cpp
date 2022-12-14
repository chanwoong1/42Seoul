/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:04:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/14 16:02:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
  std::string s1 = "chanwjeo";
  std::string s2 = "chanwoong";
  std::string s3 = "Jeong";

  FragTrap t1(s1);
  FragTrap t2(s2);
  ClapTrap t3(s3);

  std::cout << std::endl;
  t1.attack(s3);
  t3.takeDamage(t1.getAttackDamage());
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
  return 0;
}