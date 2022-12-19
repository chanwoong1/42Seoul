/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:50:50 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/19 19:01:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "AForm.hpp"

#define SET_W  30

class ShrubberyCreationForm : public AForm {
  private:
    /* data */
    static const std::string _treeOfAscii;
    std::string _target;

    ShrubberyCreationForm();

  public:
    /*
    * A default constructor
    */
    ShrubberyCreationForm(std::string target);

    /*
    * A copy constructor
    */
    ShrubberyCreationForm(const ShrubberyCreationForm& ref);

    /*
    * A assignment operator overload
    */
    ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

    /*
    * A destructor
    */
    virtual ~ShrubberyCreationForm();

    /*
    * Add it if you feel necessary additional member functions.
    */
    virtual void execute(const Bureaucrat& bureaucrat) const;
};

#endif  //ShrubberyCreationForm_HPP
