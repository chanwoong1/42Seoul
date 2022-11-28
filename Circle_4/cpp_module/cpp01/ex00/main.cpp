/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:16:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 16:18:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {
  // Create Zombie class
  Zombie zombie = Zombie("Foo");
  zombie.announce();

  // It creates a zombie, name it, and return it so you can use it outside of the function scope.
  Zombie *newZ = newZombie("newZombie");
  newZ->announce();

  // It creates a zombie, name it, and the zombie announces itself.
  randomChump("randomChump");
  return (0);
}