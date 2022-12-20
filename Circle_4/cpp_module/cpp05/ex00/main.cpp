/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:39:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/20 01:24:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
  std::cout << "test0 - insertion operator overload" << std::endl;
  Bureaucrat test0("test0", 75);
  std::cout << test0 << std::endl;

  std::cout << "test1 - out of range grade input" << std::endl;
  try {
    Bureaucrat test1("test1", 200);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "test2 - invalid increase" << std::endl;
  try {
    Bureaucrat test2("test2", 1);
    test2.incrementGrade();
    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	
  std::cout << std::endl;
  std::cout << "test3 - invalid decrease" << std::endl;
  try {
    Bureaucrat test3("test3", 150);
    test3.decrementGrade();
    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	
  std::cout << "test complete" << std::endl;
	return 0;
}