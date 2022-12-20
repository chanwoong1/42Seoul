/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:17:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 10:19:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AForm.hpp"

#define SET_W  30

class PresidentialPardonForm : public AForm{
  private:
    /* data */
    std::string _target;

    PresidentialPardonForm();

  public:
    /*
    * A default constructor
    */
    PresidentialPardonForm(std::string target);

    /*
    * A copy constructor
    */
    PresidentialPardonForm(const PresidentialPardonForm& ref);

    /*
    * A assignment operator overload
    */
    PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);

    /*
    * A destructor
    */
    ~PresidentialPardonForm();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void execute(const Bureaucrat &bureaucrat) const;
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //PresidentialPardonForm_HPP
