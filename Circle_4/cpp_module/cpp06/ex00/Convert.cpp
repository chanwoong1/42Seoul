/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/25 14:48:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
* A default constructor
*/
Convert::Convert()
  : _input(""), _value(0.0), _error(false) {
}

Convert::Convert(std::string& input)
  : _input(input), _value(0.0), _error(false) {
  try {
    char *ptr = NULL;
    *(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
    if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])))
      throw std::bad_alloc();
    if (*ptr && std::strcmp(ptr, "f"))
      throw std::bad_alloc();
  } catch (std::exception&) {
    this->_error = true;
  }
}

/*
* A copy constructor
*/
Convert::Convert(const Convert& ref)
  : _input(ref._input), _value(ref._value), _error(ref._error) {
}

/*
* A assignment operator overload
*/
Convert&	Convert::operator=(const Convert& ref) {
  if (this != &ref) {
    this->_input = ref._input;
    this->_error = ref._error;
    *(const_cast<double*>(&this->_value)) = ref._value;
  }
  return *this;
}

/*
* A destructor
*/
Convert::~Convert() {
}

const std::string& Convert::getInput() const {
  return this->_input;
}

const double& Convert::getValue() const {
  return this->_value;
}

char Convert::toChar(void) const {
  return static_cast<char>(_value);
}

int Convert::toInt(void) const {
  return static_cast<int>(_value);
}

float Convert::toFloat(void) const {
  return static_cast<float>(_value);
}

double Convert::toDouble(void) const {
  return static_cast<double>(_value);
}