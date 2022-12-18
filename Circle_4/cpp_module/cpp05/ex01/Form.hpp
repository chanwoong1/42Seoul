/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:03:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 20:36:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "Bureaucrat.hpp"

#define SET_W  30

class Form {
  private:
    /* data */
    const std::string _name;
    bool _beSigned;
    const int _signGrade;
    const int _executeGrade;

    Form();

  public:
    /*
    * A default constructor
    */
    Form(const std::string& name, const int& signGrade, const int& executeGrade);

    /*
    * A copy constructor
    */
    Form(const Form& ref);

    /*
    * A assignment operator overload
    */
    Form&	operator=(const Form& ref);

    /*
    * A destructor
    */
    ~Form();

    /*
    TODO: The grades of the Form follow the same rules that apply to the Bureaucrat. Thus, the following exceptions will be thrown if a form grade is out of bounds
    */
    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };

    /*
    * Add it if you feel necessary additional member functions.
    */

    /*
    * Getter
    */
    const std::string& getName() const;
    const bool& getBeSigned() const;
    const int& getSignGrade() const;
    const int& getExecuteGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
};

/*
* Add it if you feel necessary additional functions.
*/
std::ostream& operator<<(std::ostream& ofs, const Form& form);

#endif  //Form_HPP
