/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:03:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 02:05:40 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "Bureaucrat.hpp"

#define SET_W  30

class Bureaucrat;

class AForm {
  private:
    /* data */
    const std::string _name;
    bool _beSigned;
    const int _signGrade;
    const int _executeGrade;

    AForm();

  public:
    /*
    * A default constructor
    */
    AForm(const std::string& name, const int& signGrade, const int& executeGrade);

    /*
    * A copy constructor
    */
    AForm(const AForm& ref);

    /*
    * A assignment operator overload
    */
    AForm&	operator=(const AForm& ref);

    /*
    * A destructor
    */
    virtual ~AForm();

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

    class NotGetSign : public std::exception {
      public:
        const char* what() const throw();
    };

    class CouldNotExecute : public std::exception {
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

    /*
    * Setter
    */
    void setName(std::string name);
    void setBeSigned(bool b);

    void beSigned(const Bureaucrat& bureaucrat);
    void isExecutable(const Bureaucrat& Bureaucrat) const;
    virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

/*
* Add it if you feel necessary additional functions.
*/
std::ostream& operator<<(std::ostream& ofs, const AForm& form);

#endif
