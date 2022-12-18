/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:40:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 22:49:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>

#define SET_W  30

class AForm;

class Bureaucrat {
  private:
    /* data */
    const std::string _name;
    int _grade;

  public:
    /*
    * A default constructor
    */
    Bureaucrat();
    Bureaucrat(const std::string& name, const int& grade);

    /*
    * A copy constructor
    */
    Bureaucrat(const Bureaucrat& ref);

    /*
    * A assignment operator overload
    */
    Bureaucrat&	operator=(const Bureaucrat& ref);

    /*
    * A destructor
    */
    ~Bureaucrat();

    /*
    * Add it if you feel necessary additional member functions.
    */
    const std::string& getName() const;
    const int& getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(const AForm& form) const;

    /*
    TODO: Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
    */
    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };
};

/*
* Add it if you feel necessary additional functions.
*/
std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& ref);

#endif  //Bureaucrat_HPP
