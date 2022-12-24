/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/24 15:08:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
* A default constructor
*/
Convert::Convert()
  : _input(0), _value(0.0) {
}

Convert::Convert(std::string& input)
  : _input(input), _value(0.0) {
}

/*
* A copy constructor
*/
Convert::Convert(const Convert& ref)
  : _input(ref._input), _value(ref._value) {
}

/*
* A assignment operator overload
*/
Convert&	Convert::operator=(const Convert& ref) {
  if (this != &ref) {
    this->_input = ref._input;
    (*this)._value = ref._value;
  }
  return *this;
}

/*
* A destructor
*/
Convert::~Convert() {
}

void Convert::toChar() {
  
}
