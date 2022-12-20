/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:46:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 21:29:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
* A default constructor
*/
Intern::Intern() {
}

/*
* A copy constructor
*/
Intern::Intern(const Intern& ref) {
  (*this) = ref;
}

/*
* A assignment operator overload
*/
Intern&	Intern::operator=(const Intern& ref) {
  if (this != &ref)
    (*this) = ref;
  return *this;
}

/*
* A destructor
*/
Intern::~Intern() {
}

AForm* Intern::makeForm(std::string name, std::string target) {
  std::string findName("[" + name + "]");
  std::string findForm("[shrubbery creation][robotomy request][presidential pardon]");
  size_t pos = findName.find("][");

  if (pos >= 0 && pos <= findForm.length()) {
    std::cout << name << " is not exist. Check your parameter." << std::endl;
    return NULL;
  }
  
  AForm* createFormByIntern = NULL;
  switch (findForm.find(findName)) {
    case 0:
      createFormByIntern = new ShrubberyCreationForm(target);
      break;
    case 20:
      createFormByIntern = new RobotomyRequestForm(target);
      break;
    case 38:
      createFormByIntern = new PresidentialPardonForm(target);
      break;
    default:
      std::cout << name << " is not exist. Check your parameter." << std::endl;
      return createFormByIntern;
  }
  std::cout << "Intern creates " << (*createFormByIntern);
  return createFormByIntern;
}
