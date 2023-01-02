/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:03:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/02 23:37:45 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
* A default constructor
  ! reserve : vector의 용량을 미리 확보해둠
*/
Span::Span() : _vector(0, 0) {
  this->_vector.reserve(0);
}

Span::Span(unsigned int N) : _vector(0, 0) {
  this->_vector.reserve(N);
}

/*
* A copy constructor
*/
Span::Span(const Span& ref) : _vector(0, 0) {
  this->_vector.reserve(ref.getVector().capacity());
  if (this->_vector.capacity() != 0)
    std::copy(ref.getVector().begin(), ref.getVector().end(), std::back_inserter(this->_vector));
}

/*
* A assignment operator overload
*/
Span&	Span::operator=(const Span& ref) {
  if (this != &ref) {
    /* insert */
    this->_vector.reserve(ref.getVector().capacity());
    if (this->_vector.capacity() != 0)
      std::copy(ref.getVector().begin(), ref.getVector().end(), std::back_inserter(this->_vector));
  }
  return *this;
}

/*
* A destructor
*/
Span::~Span() {
  std::vector<int>().swap(this->_vector);
}

void Span::addNumber(int num) {
  if (this->_vector.size() == this->_vector.capacity()) throw CanNotStoreNumber();
  this->_vector.push_back(num);
}

const std::vector<int>& Span::getVector() const {
  return this->_vector;
}

std::size_t Span::shortestSpan() {
  if (this->_vector.size() <= 1) throw NotEnoughElement();
  std::vector<int> sortedVector = this->getVector();
  std::sort(sortedVector.begin(), sortedVector.end());
  std::vector<int>::iterator iter = sortedVector.begin() + 1;
  std::size_t returnValue = std::abs(*iter - *(iter - 1));
  while (iter != sortedVector.end()) {
    if (static_cast<int>(returnValue) >= std::abs(*iter - *(iter - 1)))
      returnValue = std::abs(*iter - *(iter - 1));
    ++iter;
  }
  return returnValue;
}

std::size_t Span::longestSpan() {
  if (this->_vector.size() <= 1) throw NotEnoughElement();
  return *std::max_element(this->_vector.begin(), this->_vector.end()) - *std::min_element(this->_vector.begin(), this->_vector.end());
}

const char* Span::CanNotStoreNumber::what() const throw() {
  return "Span can't add number. Not enough capacity.";
}

const char* Span::NotEnoughElement::what() const throw() {
  return "Not enough element";
}
