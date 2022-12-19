/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:59:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/19 19:01:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_treeOfAscii = "\
  ,      ,      ,,   ,\n\
      ,        ,     ,\n\
,         *       ,   \n\
         * *   ,     ,\n\
   ,    * . *     ,\n\
       * . . *      ,\n\
 ,    * .| |. *     \n\
     ****| |****   ,\n\
         | |\n\
----------------------\n\
";

/*
* A default constructor
*/
ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("shrubbery", 145, 137), _target("noTarget") {
  
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  : AForm("shrubbery", 145, 137), _target(target) {
}

/*
* A copy constructor
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
  : AForm(ref), _target(ref._target) {
}

/*
* A assignment operator overload
*/
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
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
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
	if (this->getBeSigned() == false) throw AForm::CouldNotGetSign();
	if (this->getExecuteGrade() < bureaucrat.getGrade()) throw AForm::CouldNotExecute();
  std::ofstream writeFile(_target, std::ios::out | std::ios::app);
  if (writeFile.is_open())
  {
    writeFile << this->_treeOfAscii;
    writeFile.close();
  }
}
