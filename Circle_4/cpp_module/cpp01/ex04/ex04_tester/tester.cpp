/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:27:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 17:59:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ReadFile.hpp"
#include "TestClass.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int main() {
  TestClass testClass = TestClass();

  std::cout << GRN"ex04 test start" << std::endl;

  std::cout << std::endl << CYN"ReadFile class test" << std::endl;
  std::cout << std::endl << NC"\tInvaild Input test" << std::endl;

  std::cout << "\t\t- fileName test" << std::endl;
  std::cout << "\t\t\tnot exist file" << std::endl;

  ReadFile readFile;
  try {
    testClass.addTotal();
    readFile.openFile("notExistFile", "s1", "s2");
  } catch(const char *e) {
    std::cerr << "\t\t\texpected : Error: File open failure"
      << std::endl << "\t\t\tgot : " << e << '\n';
    std::string e_string;
    e_string = e;
    (e_string.compare("Error: File open failure") == 0) ?
      testClass.addSuccess() : testClass.addFailure();
  }
  
  std::cout << std::endl;
  std::cout << NC"\t\t- Can not Read File test" << std::endl;
  std::cout << "\t\t\tdo not have file permission" << std::endl;

  try {
    testClass.addTotal();
    readFile.openFile("./srcs/can_not_read_file", "s1", "s2");
  } catch(const char *e) {
    std::cerr << "\t\t\texpected : Error: File open failure"
      << std::endl << "\t\t\tgot : " << e << '\n';
    std::string e_string;
    e_string = e;
    (e_string.compare("Error: File open failure") == 0) ?
      testClass.addSuccess() : testClass.addFailure();  
  }
  return (0);
}
