/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:56:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 05:32:17 by chanwjeo         ###   ########.fr       */
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
  tmp = src->createMateria("cure");
  std::cout << std::endl;
  me->equip(tmp);
  std::cout << std::endl;
  ICharacter* bob = new Character("bob");
  std::cout << std::endl;
  me->use(0, *bob);
  std::cout << std::endl;
  me->use(1, *bob);
  std::cout << std::endl;
  delete bob;
  delete me;
  delete src;
  return 0;
}