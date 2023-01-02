/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:36:43 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 00:11:28 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void subjectTest() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  try {
    std::cout << std::endl << "Capacity test" << std::endl;
    sp.addNumber(14);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void notWorkSpanTest() {
  Span sp2 = Span(10);
  sp2.addNumber(0);
  try {
    std::cout << "Not enough element test - shortestSpan" << std::endl;
    std::cout << sp2.shortestSpan();
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << std::endl << "Not enough element test - longestSpan" << std::endl;
    std::cout << sp2.longestSpan();
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void addManyNumbersTest() {
  std::cout << "addManyNumbers test" << std::endl;
  Span sp3 = Span(12000);
  std::cout << "Before addManyNumbers - sp3.size : " << sp3.getVector().size() << ", sp3.capacity : " << sp3.getVector().capacity() << std::endl;
  std::vector<int> v;
  for (int num = 0; num < 12000; ++num) {
    v.push_back(num);
  }
  sp3.addManyNumbers(v);
  std::cout << "After addManyNumbers - sp3.size : " << sp3.getVector().size() << ", sp3.capacity : " << sp3.getVector().capacity() << std::endl;
  std::cout << "sp3 [0 - 9] iter :";
  for (std::vector<const int>::iterator iter = sp3.getVector().begin(); iter < sp3.getVector().begin() + 10; ++iter)
    std::cout << " " << *iter;
  std::cout << std::endl << "sp3 [11990 - 11999] iter :";
  for (std::vector<const int>::iterator iter = sp3.getVector().end() - 10; iter < sp3.getVector().end(); ++iter)
    std::cout << " " << *iter;
  std::cout << std::endl;

  try {
    sp3.addNumber(12000);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

int main() {
  subjectTest();
  notWorkSpanTest();
  addManyNumbersTest();
  return 0;
}
