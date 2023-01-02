/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:18:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 01:37:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack() {};
    MutantStack(const MutantStack& ref) {*this = ref};
    MutantStack& operator=(const MutantStack& ref) {
      *this = ref;
      return *this;
    }
    ~MutantStack() {};

};

#endif  //MutantStack_HPP
