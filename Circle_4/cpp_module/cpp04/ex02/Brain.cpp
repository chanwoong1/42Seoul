/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:39:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 21:32:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
* A default constructor
*/
Brain::Brain() {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = 'A' + (i % 26); 
  }
  std::cout << std::setw(15) << "[Brain] " << "create!!" << std::endl;
}

/*
* A copy constructor
*/
Brain::Brain(const Brain& ref) {
  for (int i = 0; i < 100; i++) {
    this->setIdeas(ref.getIdeas(i), i);
  }
  std::cout << std::setw(15) << "[Brain] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
Brain&	Brain::operator=(const Brain& ref) {
  std::cout << std::setw(15) << "[Brain] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
    for (int i = 0; i < 100; i++) {
      this->setIdeas(ref.getIdeas(i), i);
    }
  }
  return *this;
}

/*
* A destructor
*/
Brain::~Brain() {
  std::cout << std::setw(15) << "[Brain] " << "delete!!" << std::endl;
}

std::string Brain::getIdeas(int n) const {
  return this->ideas[n];
}

void Brain::setIdeas(std::string idea, int n) {
  this->ideas[n] = idea;
}