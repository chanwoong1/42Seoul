/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:50:50 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 23:27:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AForm.hpp"

#define SET_W  30

class ShrubberyCreationForm : public AForm {
  private:
    /* data */
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
    ~ShrubberyCreationForm();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void execute(const Bureaucrat& bureaucrat);
};

#endif  //ShrubberyCreationForm_HPP
