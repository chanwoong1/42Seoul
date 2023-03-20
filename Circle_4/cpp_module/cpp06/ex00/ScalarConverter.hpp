/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/20 21:19:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define SET_W  30

class ScalarConverter {
  private:
    /*
    * A default constructor
    */
    ScalarConverter();

  public:

    /*
    * A copy constructor
    */
    ScalarConverter(const ScalarConverter& ref);

    /*
    * A assignment operator overload
    */
    ScalarConverter&	operator=(const ScalarConverter& ref);

    /*
    * A destructor
    */
    ~ScalarConverter();

    static void convert(const std::string& input);
};

#endif  //Convert_HPP
