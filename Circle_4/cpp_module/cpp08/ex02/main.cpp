/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:28:25 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 09:28:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() {
  MutantStack<int> mstack;
  
  mstack.push(5);
  mstack.push(17);
  
  std::cout << "mstack.top() : " << mstack.top() << std::endl;
  
  mstack.pop();
  
  std::cout << "mstack.size() : " << mstack.size() << std::endl;
  
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  
  ++it;
  --it;
  std::cout << "mstack iter :";
  while (it != ite) {
    std::cout << " " << *it;
    ++it;
  }
  std::stack<int> s(mstack);
  // std::stack<int>::iterator it = s.begin();

  std::cout << std::endl << std::endl << "list test (expected same output)" << std::endl;
  std::list<int> lst;
  
  lst.push_back(5);
  lst.push_back(17);
  
  std::cout << "lst.back() : " << lst.back() << std::endl;
  
  lst.pop_back();
  
  std::cout << "mstack.size() : " << lst.size() << std::endl;
  
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  //[...]
  lst.push_back(0);
  
  std::list<int>::iterator lstIter = lst.begin();
  std::list<int>::iterator lstIterEnd = lst.end();
  
  ++lstIter;
  --lstIter;
  std::cout << "lst iter :";
  while (lstIter != lstIterEnd) {
    std::cout << " " << *lstIter;
    ++lstIter;
  }
  std::cout << std::endl;
  return 0;
}
