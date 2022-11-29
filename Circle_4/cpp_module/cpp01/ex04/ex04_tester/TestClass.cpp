/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:40:01 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 17:57:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"
#include <iostream>

TestClass::TestClass() {
  std::cout << "테스트를 시작합니다" << std::endl;
  this->total = 0;
  this->success = 0;
  this->failure = 0;
}

TestClass::~TestClass() {
  std::cout << std::endl;
  std::cout << GRN"Total : " << this->total << std::endl
            << CYN"Success : " << this->success << std::endl
            << RED"Failure : " << this->failure << std::endl;
  std::cout << NC"테스트를 종료합니다" << std::endl;
}

void TestClass::addTotal() {
  this->total++;
}

void TestClass::addSuccess() {
  this->success++;
  std::cout << GRN"\t\t\tTEST OK" << std::endl;
}

void TestClass::addFailure() {
  this->failure++;
  std::cout << RED"\t\t\tTEST FAIL" << std::endl;
}