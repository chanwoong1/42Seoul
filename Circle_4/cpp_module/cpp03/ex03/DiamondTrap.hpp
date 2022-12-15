/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:32:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/15 12:12:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H_
#define DIAMONDTRAP_H_

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
  private:
    std::string _name;
  
  public:
    /*
    * A default constructor
    */
    DiamondTrap();
    DiamondTrap(std::string name);

    /*
    * A copy constructor
    */
    DiamondTrap(const DiamondTrap& diamondTrap);

    /*
    * A copy assignment operator
    */
    DiamondTrap& operator=(const DiamondTrap& diamondTrap);

    /*
    * A destructor
    */
    ~DiamondTrap();

    /*
    TODO: DiamondTrap will have its own special capacity
      ! This member function will display both its name and its ClapTrap name.
    */
    void wheAmI(void);
    void printStatus(void);
};

#endif
