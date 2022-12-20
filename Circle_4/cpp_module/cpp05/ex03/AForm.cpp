/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:17:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 02:36:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
* A default constructor
*/
AForm::AForm()
  : _name("default form"), _beSigned(false), _signGrade(75), _executeGrade(75) {
}

AForm::AForm(const std::string& name, const int& signGrade, const int& executeGrade)
  : _name(name), _beSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
  if (this->_signGrade < 1 || this->_executeGrade < 1) throw AForm::GradeTooHighException();
  if (this->_signGrade > 150 || this->_executeGrade > 150) throw AForm::GradeTooLowException(); 
}

/*
* A copy constructor
*/
AForm::AForm(const AForm& ref)
  : _name(ref.getName()), _beSigned(ref.getBeSigned()), _signGrade(ref.getSignGrade()), _executeGrade(ref.getExecuteGrade()) {
}

/*
* A assignment operator overload
*/
AForm&	AForm::operator=(const AForm& ref) {
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
AForm::~AForm() {
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low.";
}

const char* AForm::NotGetSign::what() const throw() {
  return "Bureaucrat have not signed form. Check your form.";
}

const char* AForm::CouldNotExecute::what() const throw() {
  return "Bureaucrat could not execute form. Grade is too low.";
}

const std::string& AForm::getName() const {
  return this->_name;
}

const bool& AForm::getBeSigned() const {
  return this->_beSigned;
}

const int& AForm::getSignGrade() const {
  return this->_signGrade;
}

const int& AForm::getExecuteGrade() const {
  return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  (bureaucrat.getGrade() <= this->getSignGrade())
    ? this->_beSigned = true : throw AForm::GradeTooHighException();
}

void AForm::setName(std::string name) {
  *(const_cast<std::string*>(&this->_name)) = name;
}

void AForm::setBeSigned(bool b) {
  this->_beSigned = b;
}

void AForm::isExecutable(const Bureaucrat& bureaucrat) const {
	if (this->getBeSigned() == false) throw AForm::NotGetSign();
	if (this->getExecuteGrade() < bureaucrat.getGrade()) throw AForm::CouldNotExecute();
}

std::ostream& operator<<(std::ostream& ofs, const AForm& form) {
  return ofs << form.getName() 
		<< std::boolalpha <<", signed : " << form.getBeSigned()
		<< ", signGrade : " << form.getSignGrade()
		<< ", executeGrade : " << form.getExecuteGrade() << std::endl;
}
