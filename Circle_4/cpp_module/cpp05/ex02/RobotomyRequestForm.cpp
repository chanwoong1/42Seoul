/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:54:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 10:11:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
* A default constructor
*/
RobotomyRequestForm::RobotomyRequestForm()
  : AForm("robotomy", 72, 45), _target("noTarget") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : AForm("robotomy", 72, 45), _target(target) {
}

/*
* A copy constructor
*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
  : AForm(ref), _target(ref._target) {
}

/*
* A assignment operator overload
*/
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
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
RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
  this->isExecutable(bureaucrat);
  std::cout << "Drilling....." << std::endl;
  std::time_t currentTime = std::time(nullptr);
  (currentTime % 2 == 0)
    ? std::cout << this->_target << " has been robotomized successful." << std::endl
    : std::cout << this->_target << " has failed to robotomize." << std::endl;
}