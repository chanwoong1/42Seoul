/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:54:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 10:11:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
* A default constructor
*/
PresidentialPardonForm::PresidentialPardonForm()
  : AForm("presidential", 25, 5), _target("noTarget") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  : AForm("presidential", 25, 5), _target(target) {
}

/*
* A copy constructor
*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
  : AForm(ref), _target(ref._target) {
}

/*
* A assignment operator overload
*/
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
  if (this != &ref) {
    /* insert */
    dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(ref);
    this->_target = ref._target;
  }
  return *this;
}

/*
* A destructor
*/
PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
  this->isExecutable(bureaucrat);
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}