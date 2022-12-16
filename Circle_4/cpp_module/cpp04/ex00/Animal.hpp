/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:12:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 10:53:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>

/*
TODO: Start by implement a simple base class called Animal.
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
      ? It will print an appropriate sound.
    */
    virtual void makeSound() const;
    std::string getType() const;
};

std::ostream& operator<<(std::ostream& ofs, const Animal& animal);

#endif
