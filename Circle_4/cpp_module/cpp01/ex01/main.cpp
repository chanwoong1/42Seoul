/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:16:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 13:16:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
// #include <stdlib.h>

int main(void) {
  // Create Zombie class
  Zombie zombie = Zombie("Foo");
  zombie.announce();

  // Create horde of Zombies!
  int N = 5;
  Zombie *zHorde = zombieHorde(N, "Bar");
  for (int i = 0; i < N; i++) {
    zHorde[i].announce();
  }
  
  delete [] zHorde;
  // system("leaks Zombie");
  return (0);
}