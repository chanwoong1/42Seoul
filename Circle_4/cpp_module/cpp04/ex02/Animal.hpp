/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:12:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 23:45:40 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>
#include <iomanip>

/*
TODO: Fix the Animal class so nobody can instantiate it. Everything should work as before.
  ? To avoid any possible mistakes, the default Animal class should not be instantiable.
*/
class Animal {
  protected:
    /*
    * Animal class has one protected attribute:
      * std::string type;
    */
    std::string _type;
  
  public:
    /*
    * A constructor
      ! Constructor of each class must display specific messages.
    */
    Animal();
    
    /*
    * A copy constructor
    */
    Animal(const Animal& animal);
    
    /*
    * A copy assignment operator
    */
    Animal& operator=(const Animal& animal);
    
    /*
    * A destructor
      ! Destructor of each class must display specific messages.
    */
    virtual ~Animal();

    /*
    TODO: Every animal must be able to use the member function:
      ! makeSound()
      ? Animal object make no sound!
    */
    virtual void makeSound() const = 0;
    std::string getType() const;
};

std::ostream& operator<<(std::ostream& ofs, const Animal& animal);

#endif
