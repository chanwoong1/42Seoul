/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:40:25 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 06:26:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
* A default constructor
*/
Bureaucrat::Bureaucrat()
  : _name("Bureaucrat"), _grade(1) {
}

Bureaucrat::Bureaucrat(std::string name, int grade)
  : _name(name), _grade(grade) {
  (this->_grade < 1) ? throw Bureaucrat::GradeTooHighException() :
  (this->_grade > 150) ? throw Bureaucrat::GradeTooLowException() : "";
}

/*
* A copy constructor
*/
Bureaucrat::Bureaucrat(const Bureaucrat& ref)
  : _name(ref.getName()), _grade(ref.getGrade()) {
  (this->_grade < 1) ? throw Bureaucrat::GradeTooHighException() :
  (this->_grade > 150) ? throw Bureaucrat::GradeTooLowException() : "";
}

/*
* A assignment operator overload
*/
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref) {
  if (this != &ref) {
    /* insert */
    *(const_cast<std::string*>(&_name)) = ref.getName();
    this->_grade = ref.getGrade();
  }
  return *this;
}

/*
* A destructor
*/
Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
  return this->_name;
}

const int& Bureaucrat::getGrade() const {
  return this->_grade;
}

void Bureaucrat::incrementGrade() {
  (this->_grade < 2) ? throw Bureaucrat::GradeTooHighException() : this->_grade--;
}

void Bureaucrat::decrementGrade() {
  (this->_grade > 149) ? throw Bureaucrat::GradeTooLowException() : this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low.";
}

std::ostream& operator<<(std::ostream ofs, const Bureaucrat& ref) {
  return ofs << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
}