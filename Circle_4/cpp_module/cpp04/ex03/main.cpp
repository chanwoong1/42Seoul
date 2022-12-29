/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:56:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/29 14:05:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  std::cout << std::endl;

  src->learnMateria(new Ice());
  std::cout << std::endl;
  src->learnMateria(new Cure());
  std::cout << std::endl;

  ICharacter* me = new Character("me");
  std::cout << std::endl;

  AMateria* tmp;
  tmp = src->createMateria("ice");
  std::cout << std::endl;
  me->equip(tmp);
  std::cout << std::endl;
  delete tmp;
  tmp = NULL;

  for (int i = 0; i < 10; i++) {
    tmp = src->createMateria("cure");
    std::cout << std::endl;
    me->equip(tmp);
    std::cout << std::endl;
    delete tmp;
    tmp = NULL;
  }

  ICharacter* bob = new Character("bob");
  std::cout << std::endl;
  me->use(0, *bob);
  std::cout << std::endl;
  me->use(1, *bob);
  std::cout << std::endl;
  
  for (int i = 0; i < 4; i++) {
    me->unequip(i);
  }
  
  delete bob;
  bob = NULL;

  delete me;
  me = NULL;

  delete src;
  src = NULL;

  system("leaks a.out");
  return 0;
}