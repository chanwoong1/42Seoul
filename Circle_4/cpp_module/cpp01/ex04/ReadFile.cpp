/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:31:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/30 21:27:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReadFile.hpp"

ReadFile::ReadFile() {
  this->pos = 0;
}

ReadFile::~ReadFile() {
}

void ReadFile::openFile(
  const std::string fileName, 
  const std::string s1, 
  const std::string s2
  ) {
  this->setArguments(fileName, s1, s2);
  this->isOpen();
  this->isValidInput();
  this->getLineInIfs();
}

void ReadFile::setArguments(
  const std::string fileName, 
  const std::string s1, 
  const std::string s2
  ) {
  this->_ifs.open(fileName);
  std::string outFile = fileName;
  outFile.append(".replace");
  this->_ofs.open(outFile);
  this->_s1 = s1;
  this->_s2 = s2;
}

void ReadFile::isOpen(void) {
  if (this->_ifs.fail() || this->_ofs.fail()) throw "Error: File open failure";
}

void ReadFile::isValidInput(void) {
  if (this->_s1.empty()) throw "Error: Invalid input string s1. do not input null";
}

void ReadFile::getLineInIfs(void) {
  while (getline(this->_ifs, this->_readLine)) {
    this->pos = 0;
    this->replaceString();
    this->_ofs << this->_readLine << std::endl;
  }
}

void ReadFile::replaceString(void) {
  while (1) {
    this->pos = this->_readLine.find(this->_s1, this->pos);
    if (this->pos == std::string::npos)
      break;
    this->_readLine.erase(this->pos, this->_s1.length());
    this->_readLine.insert(this->pos, this->_s2);
    this->pos += this->_s2.length();
  }
}