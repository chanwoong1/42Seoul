/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:20:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/20 00:32:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define SET_W  30

struct Data {
  std::string name;
};

class Serializer {
  public:
    /*
    * A default constructor
    */
    Serializer();

    /*
    * A copy constructor
    */
    Serializer(const Serializer& ref);

    /*
    * A assignment operator overload
    */
    Serializer&	operator=(const Serializer& ref);

    /*
    * A destructor
    */
    ~Serializer();

    /*
    * Add it if you feel necessary additional member functions.
    */
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //Serializer_HPP
