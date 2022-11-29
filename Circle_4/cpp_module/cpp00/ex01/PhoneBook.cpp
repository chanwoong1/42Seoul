/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:30:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 13:05:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
  idx = 0;
}

PhoneBook::~PhoneBook() {
}

Contact PhoneBook::CraeteContact() {
  std::string contactInfo[5];
  std::string coutList[5];
  coutList[0] = "first name> ";
  coutList[1] = "last name> ";
  coutList[2] = "nick name> ";
  coutList[3] = "phone number> ";
  coutList[4] = "darkest secret> ";

  for (int i = 0; i < 5; i++) {
    std::cout << coutList[i];
    std::getline(std::cin, contactInfo[i]);
    if (std::cin.eof()) {
      std::cout << "Enter EOF. Program Exit." << std::endl;
    }
  }
  return Contact(contactInfo[0], contactInfo[1], contactInfo[2], contactInfo[3], contactInfo[4]);
}

void PhoneBook::AddContact() {
  contact[idx % 8] = CraeteContact();
  idx += 1;
  (idx > 16) ? idx -= 8 : idx;
}

void PhoneBook::SearchContact() {
  std::cout << "┌───────┬────────────┬────────────┬────────────┐" << std::endl;
  std::cout << "│ index │ first name │  last name │   nickname │" << std::endl;
  std::cout << "├───────┼────────────┼────────────┼────────────┤" << std::endl;

  for (int i = 0; i < 8; i++) {
    if (idx < 8 && idx == i)
      break ;
    std::cout << "│   " << i % 8 + 1 << "   │";
    DisplaySearchList(contact[i].GetFirstName());
    DisplaySearchList(contact[i].GetLastName());
    DisplaySearchList(contact[i].GetNickName());
    std::cout << "\n";
  }
  std::cout << "└───────┴────────────┴────────────┴────────────┘" << std::endl;
  if (this->idx != 0)
    DisplayContact();
}

void PhoneBook::DisplaySearchList(std::string contactInfo) {
  int contactLen = contactInfo.length();

  if (contactLen < 10) {
    for (int i = 0; i < 12 - contactLen - 1; i++)
      std::cout << " ";
    std::cout << contactInfo << " │";
  } else if (contactLen == 10) {
    std::cout << " " << contactInfo << " │";
  } else {
    std::cout << " ";
    for (int i = 0; i < 9; i++) {
      std::cout << contactInfo[i];
    }
    std::cout << ". │";
  }
}

void PhoneBook::DisplayContact() {
  std::string inputIndex;
  int index;
  
  std::cout << std::endl << "Input index> ";
  while (1) {
    std::getline(std::cin, inputIndex);
    if (std::cin.eof()) {
      std::cout << "Enter EOF. Program Exit." << std::endl;
      break;
    }
    try {
      ValidateInputIndex(inputIndex);
      index = std::atoi(inputIndex.c_str());
      std::cout << "first name : " << contact[index - 1].GetFirstName() << std::endl;
      std::cout << "last name : " << contact[index - 1].GetLastName() << std::endl;
      std::cout << "nickname : " << contact[index - 1].GetNickName() << std::endl;
      std::cout << "phone number : " << contact[index - 1].GetPhoneNumber() << std::endl;
      std::cout << "darkest secret : " << contact[index - 1].GetDarkestSecret() << std::endl;
      break;
    } catch (const char* message) {
      std::cout << message;
      std::cout << std::endl << "Input index> ";
    }
  }
}

void PhoneBook::ValidateInputIndex(std::string inputIndex) {
  if (inputIndex.length() != 1) throw "Invalid input - length\n";
  if (isdigit(inputIndex[0]) == 0) throw "Invalid input - It's not integer\n";
  if (!(std::atoi(inputIndex.c_str()) <= 8 && std::atoi(inputIndex.c_str()) >= 1)) throw "Invalid input - Out of range\n";
  if (this->idx < 8 && std::atoi(inputIndex.c_str()) >= this->idx + 1) throw "Invalid input - Out of range\n";
}
