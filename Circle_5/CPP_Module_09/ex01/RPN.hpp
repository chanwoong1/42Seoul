/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:24:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/28 22:08:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <sstream>

#define SET_W  30

class RPN {
  private:
    /* data */
    std::stack<double> rpn;
    std::stack<std::string> splitString;
    int numberOfValues;

    RPN();
  public:
    /*
    * A default constructor
    */
    RPN(char *av);

    /*
    * A copy constructor
    */
    RPN(const RPN& ref);

    /*
    * A assignment operator overload
    */
    RPN&	operator=(const RPN& ref);

    /*
    * A destructor
    */
    ~RPN();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void split(char *av);
    void validateInput(std::string s);
    bool isOperator(char op);
    void calculate();
    double calculator(double a, double b, char op);

    class Error : public std::exception {
      public:
        const char* what() const throw();
    };
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //RPN_HPP
