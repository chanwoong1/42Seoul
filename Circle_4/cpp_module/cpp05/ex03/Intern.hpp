/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:44:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 21:45:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AForm.hpp"

#define SET_W  30

class Intern {
  private:
    /* data */

  public:
    /*
    * A default constructor
    */
    Intern();

    /*
    * A copy constructor
    */
    Intern(const Intern& ref);

    /*
    * A assignment operator overload
    */
    Intern&	operator=(const Intern& ref);

    /*
    * A destructor
    */
    ~Intern();

    /*
    * Add it if you feel necessary additional member functions.
    */

    /*
    TODO: The intern has one important capacity: the makeForm() function.
      ? It takes two strings. The first one is the name of a form and the second one is the target of the form.
      ! It return a pointer to a Form object.
    */
    AForm* makeForm(std::string name, std::string target);
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //Intern_HPP
