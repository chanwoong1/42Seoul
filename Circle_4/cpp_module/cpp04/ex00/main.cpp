/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:35:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 18:05:38 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();
  // ...

  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();
  wrongMeta->makeSound();
  wrongCat->makeSound();
  delete meta;
  delete i;
  delete j;
  delete wrongMeta;
  delete wrongCat;
  return 0;
}