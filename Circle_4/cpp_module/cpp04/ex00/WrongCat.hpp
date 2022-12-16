/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:33:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 18:39:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  public:
    /*
    * A default constructor
    */
    WrongCat();

    /*
    * A copy constructor
    */
    WrongCat(const WrongCat& ref);

    /*
    * A assignment operator overload
    */
    WrongCat&	operator=(const WrongCat& ref);

    /*
    * A destructor
    */
    virtual ~WrongCat();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void makeSound() const;
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //WrongCat_HPP
