/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:35:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 23:05:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 4; i++) {
		(i % 2) ? meta[i] = new Dog() : meta[i] = new Cat();
    std::cout << std::endl;
  }
	std::cout << std::endl;

	for (size_t i = 0; i < 4; i++) {
		delete meta[i];
    std::cout << std::endl;
  }
	std::cout << std::endl;
	
	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl;
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	d->getBrain()->setIdeas("something", 0);
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "Dog2's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;

	return 0;
}