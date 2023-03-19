/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/19 23:57:44 by chanwjeo         ###   ########.fr       */
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
    /* data */
    std::string _input;
    const double _value;
    bool _error;

  public:
    /*
    * A default constructor
    */
    ScalarConverter();

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

    const std::string& getInput() const;
    const double& getValue() const;
    const bool& getError() const;

    void convert(const std::string& input);

    /*
    * Add it if you feel necessary additional member functions.
    */
    char toChar() const;
    int toInt() const;
    float toFloat() const;
    double toDouble() const;
    static void printResult(std::ostream& ofs, const ScalarConverter& convert);
};

/*
* Add it if you feel necessary additional functions.
*/
std::ostream& operator<<(std::ostream& ofs, const ScalarConverter& convert);

#endif  //Convert_HPP
