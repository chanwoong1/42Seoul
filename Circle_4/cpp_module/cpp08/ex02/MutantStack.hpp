/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:18:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 09:24:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack() {};
    MutantStack(const MutantStack& ref) {*this = ref;};
    MutantStack& operator=(const MutantStack& ref) {
      *this = ref;
      return *this;
    }
    ~MutantStack() {};

    /*
    TODO: Plus an additional feature: iterators.
    */
    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}

    typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() {return this->c.rbegin();}
    reverse_iterator rend() {return this->c.rend();}
};

#endif  //MutantStack_HPP
