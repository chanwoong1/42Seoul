/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:50:15 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/30 11:05:58 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void intArrayTest() {
  std::cout << "Int array test start" << std::endl << std::endl;

  int intArray1[10];
  for (int i = 0; i < 10; i++) {
    intArray1[i] = i;
  }
  printArray(intArray1, 10);

  std::cout << std::endl << "iter to multiple2 function" << std::endl;
  iter(intArray1, 10, multiple2);
  printArray(intArray1, 10);
}


int main() {
  intArrayTest();
  return 0;

}