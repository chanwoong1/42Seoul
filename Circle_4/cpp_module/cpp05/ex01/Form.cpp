/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:17:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 21:08:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
* A default constructor
*/
Form::Form()
  : _name("default form"), _beSigned(false), _signGrade(75), _executeGrade(75) {
}

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade)
  : _name(name), _beSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
  if (this->_signGrade < 1 || this->_executeGrade < 1) throw Form::GradeTooHighException();
  if (this->_signGrade > 150 || this->_executeGrade > 150) throw Form::GradeTooLowException(); 
}

/*
* A copy constructor
*/
Form::Form(const Form& ref)
  : _name(ref.getName()), _beSigned(ref.getBeSigned()), _signGrade(ref.getSignGrade()), _executeGrade(ref.getExecuteGrade()) {
}

/*
* A assignment operator overload
*/
Form&	Form::operator=(const Form& ref) {
  if (this != &ref) {
    /* insert */
    *(const_cast<std::string*>(&this->_name)) = ref.getName();
    *(const_cast<int*>(&this->_signGrade)) = ref.getSignGrade();
    *(const_cast<int*>(&this->_executeGrade)) = ref.getExecuteGrade();
    this->_beSigned = ref.getBeSigned();
  }
  return *this;
}

/*
* A destructor
*/
Form::~Form() {
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low.";
}

const std::string& Form::getName() const {
  return this->_name;
}

const bool& Form::getBeSigned() const {
  return this->_beSigned;
}

const int& Form::getSignGrade() const {
  return this->_signGrade;
}

const int& Form::getExecuteGrade() const {
  return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= this->getSignGrade()) {
    std::cout << bureaucrat.getName() << " is Signed" << std::endl;
    this->_beSigned = true;
    return ;
  }
  throw Form::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& ofs, const Form& form) {
  return ofs << form.getName() 
		<< std::boolalpha <<", signed : " << form.getBeSigned()
		<< ", signGrade : " << form.getSignGrade()
		<< ", executeGrade : " << form.getExecuteGrade();
}
