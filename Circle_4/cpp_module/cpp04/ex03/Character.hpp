/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:52:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 04:54:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
#define Character_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
  private:
    /* data */
    std::string _name;
    AMateria*   _inventory[4];

  public:
    /*
    * A default constructor
    */
    Character();
    Character(std::string name);

    /*
    * A copy constructor
    */
    Character(const Character& ref);

    /*
    * A assignment operator overload
    */
    Character&	operator=(const Character& ref);

    /*
    * A destructor
    */
    virtual ~Character();

    /*
    * Add it if you feel necessary additional member functions.
    */
    std::string const &getName();
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif  //Character_HPP
