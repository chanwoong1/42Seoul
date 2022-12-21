/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/21 23:36:40 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
* A default constructor
*/
Convert::Convert() {
}

Convert::Convert(char c) {
  std::cout << "char: " << c << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << 
}

/*
* A copy constructor
  *this = ref;
  std::cout << std::setw(SET_W) << "[Convert] " << "copy!!" << std::endl;
}

/*
*/
  std::cout << std::setw(SET_W) << "[Convert] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
  }
  return *this;
/*
* A destructor
*/
Convert::~Convert() {
  std::cout << std::setw(SET_W) << "[Convert] " << "delete!!" << std::endl;
}