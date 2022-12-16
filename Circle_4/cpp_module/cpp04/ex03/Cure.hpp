/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:44:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 04:33:45 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
#define Cure_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AMateria.hpp"

class Cure : public AMateria {
  public:
    /*
    * A default constructor
    */
    Cure();

    /*
    * A copy constructor
    */
    Cure(const Cure& ref);

    /*
    * A assignment operator overload
    */
    Cure&	operator=(const Cure& ref);

    /*
    * A destructor
    */
    ~Cure();

    /*
    * Add it if you feel necessary additional member functions.
    */
    AMateria *clone() const;
    void use(ICharacter& target);

};

#endif  //Cure_HPP
