/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:39:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/18 20:46:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void prevTest() {
  std::cout << "previous test start" << std::endl << std::endl;
  std::cout << "test1 - out of range grade input" << std::endl;
  try {
    Bureaucrat test1("test1", 200);
    std::cout << "This message is not print." << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "test2 - invalid increase" << std::endl;
  try {
    Bureaucrat test2("test2", 1);
    test2.incrementGrade();
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	
  std::cout << std::endl;
  std::cout << "test3 - invalid decrease" << std::endl;
  try {
    Bureaucrat test3("test3", 150);
    test3.decrementGrade();
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl << "previous test complete" << std::endl;
}

int main() {
  prevTest();

  std::cout << std::endl << "test1 - out of range form sign grade" << std::endl;
  try {
    std::cout << "Form form1(\"form1\", 0, 75);" << std::endl;
    Form form2("form1", 0, 75);
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << std::endl;
    std::cout << "Form form2(\"form2\", 75, 151);" << std::endl;
    Form form2("form2", 0, 75);
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "test2 - beSigned test" << std::endl;
  std::cout << "Form form3(\"form3\", 75, 75);" << std::endl;
  Form form3("form3", 75, 75);
  try {
    Bureaucrat bu3("bu3", 76);
    form3.beSigned(bu3);
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  
  try {
    Bureaucrat bu4("bu4", 74);
    form3.beSigned(bu4);
  } catch (std::exception& e) {
    std::cout << "This message is not print." << std::endl;
  }

  std::cout << std::endl;
  std::cout << "test3 - signForm test" << std::endl;
  std::cout << "Form form(\"form\", 75, 75);" << std::endl;
  std::cout << "Bureaucrat bu(\"bu\", 74);" << std::endl;
  try {
    Bureaucrat bu("bu", 74);
    bu.signForm(form3);
  } catch (std::exception& e) {
    std::cout << "This message is not print." << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Form form(\"form\", 75, 75);" << std::endl;
  std::cout << "Bureaucrat bu(\"bu\", 76);" << std::endl;
  try {
    Bureaucrat bu("bu", 76);
    bu.signForm(form3);
  } catch (std::exception& e) {
    std::cout << "This message is not print." << std::endl;
  }

  std::cout << "test complete" << std::endl;
	return 0;
}
