/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:27:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/02 13:17:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
  std::vector<int> v;
  std::list<int> lst;
  std::deque<int> dq;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
    lst.push_back(i);
    dq.push_back(i);
  }
  v.push_back(5);
  lst.push_back(5);
  dq.push_back(5);

  try {
    std::cout << "VECTOR" << std::endl;
    std::cout << *(easyfind(v, 5)) << " index is " << std::distance(v.begin(), easyfind(v, 5)) << std::endl;
    std::cout << *(easyfind(v, -1)) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  
  try {
    std::cout << "LIST" << std::endl;
    std::cout << *(easyfind(lst, 5)) << " index is " << std::distance(lst.begin(), easyfind(lst, 5)) << std::endl;
    std::cout << *(easyfind(lst, -1)) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;

  try {
    std::cout << "DEQUE" << std::endl;
    std::cout << *(easyfind(dq, 5)) << " index is " << std::distance(dq.begin(), easyfind(dq, 5)) << std::endl;
    std::cout << *(easyfind(dq, -1)) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}