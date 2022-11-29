/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:31:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 14:24:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReadFile.hpp"

ReadFile::ReadFile() {
}

ReadFile::~ReadFile() {
}

void ReadFile::openFile(
  const std::string fileName, 
  const std::string s1, 
  const std::string s2
  ) {
  this->_ifs.open(fileName);
  this->_s1 = s1;
  this->_s2 = s2;
  this->isOpen();
}

void ReadFile::isOpen(void) {
  if (this->_ifs.fail()) throw "Error: File open failure";
}

void ReadFile::isValidInput(void) {
  if (this->_s1.empty() || this->_s2.empty()) throw "Error: Invalid input string";
}
