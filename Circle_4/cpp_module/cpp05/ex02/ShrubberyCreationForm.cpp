/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:59:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 23:31:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
* A default constructor
*/
ShrubberyCreationForm::ShrubberyCreationForm() {
  this->setName("default shrubbery");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) {
  this->setName(target);
}

/*
* A copy constructor
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) {
  this->setName(ref.getName());
}

/*
* A assignment operator overload
*/
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
  if (this != &ref) {
    /* insert */
    this->setName(ref.getName());
  }
  return *this;
}

/*
* A destructor
*/
ShrubberyCreationForm::~ShrubberyCreationForm() {
}
