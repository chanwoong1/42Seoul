/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/22 18:33:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
* A default constructor
*/
Convert::Convert() : _input(0), _value(0.0) {
}

Convert::Convert(std::string& input) : _input(input), _value(0.0) {
  
}

/*
* A copy constructor
*/
Convert::Convert(const Convert& ref) {
  *this = ref;
  std::cout << std::setw(SET_W) << "[Convert] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
Convert&	Convert::operator=(const Convert& ref) {
  std::cout << std::setw(SET_W) << "[Convert] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
  }
  return *this;
}

/*
* A destructor
*/
Convert::~Convert() {
  std::cout << std::setw(SET_W) << "[Convert] " << "delete!!" << std::endl;
}

void Convert::toChar() {
  
}