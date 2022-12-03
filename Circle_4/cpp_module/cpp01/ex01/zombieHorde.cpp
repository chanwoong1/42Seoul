/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:22:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/03 23:03:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name ) {
  Zombie *zHorde = new Zombie[N];
  std::stringstream	stringStream;

  for (int i = 0; i < N; i++) {
    stringStream.str(std::string());
		stringStream << i + 1;
    zHorde[i].setName(name + "_" + stringStream.str());
  }
  return zHorde;
}