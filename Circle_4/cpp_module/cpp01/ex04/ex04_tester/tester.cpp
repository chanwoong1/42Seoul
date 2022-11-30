/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:27:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/30 21:28:29 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ReadFile.hpp"
#include "TestClass.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define BLUE "\033[0;94m"

int main() {
  TestClass testClass = TestClass();
  ReadFile readFile;

  std::cout << GRN"ex04 test start" << std::endl;

  std::cout << std::endl << CYN"ReadFile class test" << std::endl;
  std::cout << std::endl << NC"\tInvaild Input test" << std::endl;

  std::cout << BLUE"\t\t- fileName test" << std::endl;

  std::cout << NC"\t\t\t- not exist file" << std::endl;
  try {
    testClass.addTotal();
    readFile.openFile("./ex04_tester/notExistFile", "s1", "s2");
  } catch(const char *e) {
    std::cerr << "\t\t\texpected : Error: File open failure"
      << std::endl << "\t\t\tgot      : " << e << '\n';
    std::string e_string;
    e_string = e;
    (e_string.compare("Error: File open failure") == 0) ?
      testClass.addSuccess() : testClass.addFailure();
  }

  std::cout << std::endl << NC"\t\t\t- null" << std::endl;
  try {
    testClass.addTotal();
    readFile.openFile("./ex04_tester/", "s1", "s2");
  } catch(const char *e) {
    std::cerr << "\t\t\texpected : Error: File open failure"
      << std::endl << "\t\t\tgot      : " << e << '\n';
    std::string e_string;
    e_string = e;
    (e_string.compare("Error: File open failure") == 0) ?
      testClass.addSuccess() : testClass.addFailure();
  }

  std::cout << std::endl;
  std::cout << BLUE"\t\t- Can not Read File test" << std::endl;
  std::cout << NC"\t\t\t- do not have file permission" << std::endl;

  try {
    testClass.addTotal();
    readFile.openFile("./ex04_tester/can_not_read_file", "s1", "s2");
  } catch(const char *e) {
    std::cerr << "\t\t\texpected : Error: File open failure"
      << std::endl << "\t\t\tgot      : " << e << '\n';
    std::string e_string;
    e_string = e;
    (e_string.compare("Error: File open failure") == 0) ?
      testClass.addSuccess() : testClass.addFailure();  
  }

  std::cout << std::endl;
  std::cout << BLUE"\t\t- string s1 test" << std::endl;
  std::cout << NC"\t\t\t- null input" << std::endl;

  ReadFile readFile1;

  try {
    testClass.addTotal();
    std::string fileName = "./ex04_tester/hello";
    std::string s1 = "";
    std::string s2 = "s2";
    readFile1.openFile(fileName, s1, s2);
  } catch(const char *e) {
    std::cerr << "\t\t\texpected : Error: Invalid input string s1. do not input null"
      << std::endl << "\t\t\tgot      : " << e << '\n';
    std::string e_string;
    e_string = e;
    (e_string.compare("Error: Invalid input string s1. do not input null") == 0) ?
      testClass.addSuccess() : testClass.addFailure();
  }
  return (0);
}
