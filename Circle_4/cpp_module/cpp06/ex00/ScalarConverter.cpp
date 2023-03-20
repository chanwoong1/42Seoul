/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/20 21:19:41 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
TODO: Input must convert to double type.
  ! If were not convert input, occur error.
*/
void ScalarConverter::convert(const std::string& input) {
  double value;
  try {
    char *ptr = NULL;
    value = std::strtod(input.c_str(), &ptr);
    if (value == 0.0 &&
      (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])) &&
      (*ptr && std::strcmp(ptr, "f")))
      throw std::bad_alloc();
  } catch (...) {
    std::cout << "Convert Failure" << std::endl;
    return ;
  }
  /*
  * char
  TODO: Nan and inf are not convert to char type.
    ! If converted value is non-printable, display a message to inform the user that the type conversion is not displayable.
  */
  std::cout << "char: ";
  (std::isnan(value) || std::isinf(value))
    ? std::cout << "impossible" << std::endl : std::isprint(static_cast<char>(value))
    ? std::cout << "'" << static_cast<char>(value) << "'" << std::endl : std::cout << "Non displayable" << std::endl;

  /*
  * int
  TODO: Nan and inf are not convert to int type.
    ! If a conversion does not make overflows, display a message to inform the user that the type conversion is impossible.
  */
  std::cout << "int: ";
  (std::isnan(value) || std::isinf(value) ||
  (value > 2147483647 || value < -2147483648))
    ? std::cout << "impossible" << std::endl : std::cout << static_cast<int>(value) << std::endl;

  /*
  * float, double
  TODO: Float type and double type are possible to display conversion.
    ! Because input is already converted to double type.
  */
  if (std::isnan(value) || std::isinf(value)) {
    std::cout << "float: " << std::showpos << static_cast<float>(value) << "f" << std::endl << "double: " << static_cast<double>(value) << std::endl;
    return ;
  }

  (static_cast<float>(value) == static_cast<int64_t>(static_cast<float>(value)))
    ? std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl
    : std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << std::endl;

  (static_cast<double>(value) == static_cast<int64_t>(static_cast<double>(value)))
    ? std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl
    : std::cout << "double: " << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<double>(value) << std::endl;
}

/*
* A copy constructor
*/
ScalarConverter::ScalarConverter(const ScalarConverter& ref) {
  *this = ref;
}

/*
* A assignment operator overload
*/
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& ref) {
  (void)ref;
  return *this;
}

/*
* A destructor
*/
ScalarConverter::~ScalarConverter() {
}
