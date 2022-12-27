/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/28 01:28:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
* A default constructor
*/
Convert::Convert()
  : _input(""), _value(0.0), _error(false) {
}

/*
TODO: Input must convert to double type.
  ! If were not convert input, occur error.
*/
Convert::Convert(const std::string& input)
  : _input(input), _value(0.0), _error(false) {
  try {
    char *ptr = NULL;
    *(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
    if (_value == 0.0 &&
      (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])) &&
      (*ptr && std::strcmp(ptr, "f")))
      throw std::bad_alloc();
  } catch (...) {
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

const bool& Convert::getError() const {
  return this->_error;
}

/*
* static_cast
  ! Converts between types using a combination of implicit and user-defined conversions.
*/
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

/*
* Display output
*/
static void printResult(std::ostream& ofs, const Convert& convert) {
  /*
  * char
  TODO: Nan and inf are not convert to char type.
    ! If converted value is non-printable, display a message to inform the user that the type conversion is not displayable.
  */
  ofs << "char: ";
  (std::isnan(convert.getValue()) || std::isinf(convert.getValue()))
    ? ofs << "impossible" << std::endl : (std::isprint(convert.toChar()))
    ? ofs << "'" << convert.toChar() << "'" << std::endl : ofs << "Non displayable" << std::endl;
  
  /*
  * int
  TODO: Nan and inf are not convert to int type.
    ! If a conversion does not make overflows, display a message to inform the user that the type conversion is impossible.
  */
  ofs << "int: ";
  (std::isnan(convert.getValue()) || std::isinf(convert.getValue()) ||
  (convert.getValue() > 2147483647 || convert.getValue() < -2147483648))
    ? ofs << "impossible" << std::endl : ofs << convert.toInt() << std::endl;

  /*
  * float, double
  TODO: Float type and double type are possible to display conversion.
    ! Because input is already converted to double type.
  */
  if (std::isnan(convert.getValue()) || std::isinf(convert.getValue())) {
    ofs << "float: " << std::showpos << convert.toFloat() << "f" << std::endl << "double: " << convert.toDouble() << std::endl;
    return ;
  }

  (convert.toFloat() == static_cast<int64_t>(convert.toFloat()))
    ? ofs << "float: " << convert.toFloat() << ".0f" << std::endl
    : ofs << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << convert.toFloat() << "f" << std::endl;

  (convert.toDouble() == static_cast<int64_t>(convert.toDouble()))
    ? ofs << "double: " << convert.toDouble() << ".0" << std::endl
    : ofs << "double: " << std::setprecision(std::numeric_limits<float>::digits10) << convert.toDouble() << "f" << std::endl;
}

std::ostream& operator<<(std::ostream& ofs, const Convert& convert) {
  if (convert.getError()) {
    return ofs << "Convert Failure" << std::endl;
  }
  return printResult(ofs, convert), ofs;
}
