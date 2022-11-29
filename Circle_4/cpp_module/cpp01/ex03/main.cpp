/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:33:30 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 09:02:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
  std::cout << "Create HumanA class" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", &club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  
  std::cout << std::endl << "Create HumanB class" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(&club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
return 0;
}