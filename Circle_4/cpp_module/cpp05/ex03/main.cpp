/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:39:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 21:32:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void shrubberyTest(Bureaucrat b1, Bureaucrat b4) {
  std::cout << "ShrubberyCreateForm test" << std::endl;
  Intern  someRandomIntern;
  AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "Christmas");
  AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "Tree");
  someRandomIntern.makeForm("shrubbery cr", "Christmas");
  someRandomIntern.makeForm("shrubbery creation][robotomy request", "Christmas");

  std::cout << std::endl;
  std::cout << "Grade 140, can sign Shrubbery?" << std::endl;
  b4.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 140, can execute Shrubbery?" << std::endl;
  b4.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Shrubbery?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Shrubbery?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);
  std::cout << std::endl;

  delete f1;
  delete f2;
}

void robotomyTest(Bureaucrat b1, Bureaucrat b3) {
  std::cout << std::endl << "RobotomyRequestForm test" << std::endl;
  Intern  someRandomIntern;
  AForm* f1 = someRandomIntern.makeForm("robotomy request", "f1");
  AForm* f2 = someRandomIntern.makeForm("robotomy request", "f2");
  someRandomIntern.makeForm("robotomy requ", "f1");
  someRandomIntern.makeForm("robotomy request][presidential pardon", "f2");

  std::cout << std::endl;
  std::cout << "Grade 70, can sign Robotomy?" << std::endl;
  b3.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 70, can execute Robotomy?" << std::endl;
  b3.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Robotomy?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Robotomy?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);
  std::cout << std::endl;

  delete f1;
  delete f2;
}

void presidentialTest(Bureaucrat b1, Bureaucrat b2) {
  std::cout << std::endl << "PresidentialPardonForm test" << std::endl;
  Intern  someRandomIntern;
  AForm* f1 = someRandomIntern.makeForm("presidential pardon", "f1");
  AForm* f2 = someRandomIntern.makeForm("presidential pardon", "f2");
  someRandomIntern.makeForm("presidential", "f1");
  someRandomIntern.makeForm("presidential pardo", "f2");

  std::cout << std::endl;
  std::cout << "Grade 70, can sign Pardon Form?" << std::endl;
  b2.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 70, can execute Pardon?" << std::endl;
  b2.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Pardon?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Pardon?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);
  std::cout << std::endl;

  delete f1;
  delete f2;
}

int main(void) {
  Bureaucrat b1("Admin", 1);
  Bureaucrat b2("chanwjeo", 15);
  Bureaucrat b3("chanwoong", 70);
  Bureaucrat b4("jeong", 140);

  std::cout << b1 << b2 << b3 << b4 << std::endl;
  shrubberyTest(b1, b4);
  robotomyTest(b1, b3);
  presidentialTest(b1, b2);
  // system("leaks a.out");
  return 0;
}