/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:44:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 03:44:55 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_HPP
#define Ice_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AMateria.hpp"

class Ice : public AMateria {
  public:
    /*
    * A default constructor
    */
    Ice();

    /*
    * A copy constructor
    */
    Ice(const Ice& ref);

    /*
    * A assignment operator overload
    */
    Ice&	operator=(const Ice& ref);

    /*
    * A destructor
    */
    ~Ice();

    /*
    * Add it if you feel necessary additional member functions.
    */
    AMateria *clone() const;
    void use(ICharacter& target);
};

#endif  //Ice_HPP
