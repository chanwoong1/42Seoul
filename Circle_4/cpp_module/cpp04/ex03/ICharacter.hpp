/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:03:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 05:10:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter_HPP
#define ICharacter_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AMateria.hpp"

class AMateria;

/*
TODO: Write the concrete class Character which will implement the following interface.
*/
class ICharacter {
  public:
    virtual ~ICharacter() {};
    virtual std::string const& getName() = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif  //ICharacter_HPP
