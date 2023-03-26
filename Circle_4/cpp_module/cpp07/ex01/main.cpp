/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:50:15 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/23 16:46:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void) {
  std::string s[6] = { "42", "Seoul", "cpp", "module", "07", "chanwjeo" };
  int i[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  double d[10] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  char c[12] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' };

  std::cout << "Iter test" << std::endl << std::endl;
  std::cout << "String Iteration\t: ";
  ::iter(s, 6, print);
  std::cout << std::endl;
  std::cout << "Int Iteration\t\t: ";
  ::iter(i, 10, print);
  std::cout << std::endl;
  std::cout << "Double Iteration\t: ";
  ::iter(d, 10, print);
  std::cout << std::endl;
  std::cout << "Char Iteration\t\t: ";
  ::iter(c, 12, print);
  std::cout << std::endl;
  return 0;
}
