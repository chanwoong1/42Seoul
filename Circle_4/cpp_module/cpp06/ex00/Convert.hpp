/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/28 00:00:42 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Convert_HPP
#define Convert_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define SET_W  30

class Convert {
  private:
    /* data */
    std::string _input;
    const double _value;
    bool _error;

    Convert();
  public:
    /*
    * A default constructor
    */
    Convert(const std::string& input);

    /*
    * A copy constructor
    */
    Convert(const Convert& ref);

    /*
    * A assignment operator overload
    */
    Convert&	operator=(const Convert& ref);

    /*
    * A destructor
    */
    ~Convert();

    const std::string& getInput() const;
    const double& getValue() const;
    const bool& getError() const;

    /*
    * Add it if you feel necessary additional member functions.
    */
    char toChar() const;
    int toInt() const;
    float toFloat() const;
    double toDouble() const;
    static void printResult(std::ostream& ofs, const Convert& convert);
};

/*
* Add it if you feel necessary additional functions.
*/
std::ostream& operator<<(std::ostream& ofs, const Convert& convert);

#endif  //Convert_HPP
