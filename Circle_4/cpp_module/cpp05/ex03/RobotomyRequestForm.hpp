/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:48:40 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 09:57:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "AForm.hpp"

#define SET_W  30

class RobotomyRequestForm : public AForm{
  private:
    /* data */
    std::string _target;

    RobotomyRequestForm();

  public:
    /*
    * A default constructor
    */
    RobotomyRequestForm(std::string target);

    /*
    * A copy constructor
    */
    RobotomyRequestForm(const RobotomyRequestForm& ref);

    /*
    * A assignment operator overload
    */
    RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);

    /*
    * A destructor
    */
    ~RobotomyRequestForm();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void execute(const Bureaucrat &bureaucrat) const;
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //RobotomyRequestForm_HPP
