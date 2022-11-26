/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:30:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/26 19:08:43 by chanwjeo         ###   ########.fr       */
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
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
  
  std::cout << "first name> ";
  std::getline(std::cin, firstName);
  std::cout << "last name> ";
  std::getline(std::cin, lastName);
  std::cout << "nick name> ";
  std::getline(std::cin, nickName);
  std::cout << "phone number> ";
  std::getline(std::cin, phoneNumber);
  std::cout << "darkest secret> ";
  std::getline(std::cin, darkestSecret);
  std::cout << std::endl;
  return Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

void PhoneBook::AddContact() {
  contact[idx % 8] = CraeteContact();
  idx++;
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
  while (std::getline(std::cin, inputIndex)) {
    try {
      ValidateInputIndex(inputIndex);
      index = std::stoi(inputIndex);
      std::cout << "first name : " << contact[index - 1].GetFirstName() << std::endl;
      std::cout << "last name : " << contact[index - 1].GetLastName() << std::endl;
      std::cout << "nickname : " << contact[index - 1].GetNickName() << std::endl;
      std::cout << "phone number : " << contact[index - 1].GetPhoneNumber() << std::endl;
      std::cout << "darkest secret : " << contact[index - 1].GetDarkestSecret() << std::endl;
      break;
    }
    catch (const char* message) {
      std::cout << message;
      std::cout << std::endl << "Input index> ";
    }
  }
}

void PhoneBook::ValidateInputIndex(std::string inputIndex) {
  if (inputIndex.length() != 1) throw "Invalid input - length\n";
  if (isdigit(inputIndex[0]) == 0) throw "Invalid input - It's not integer\n";
  if (!(std::stoi(inputIndex) <= 8 && std::stoi(inputIndex) >= 1)) throw "Invalid input - Out of range\n";
  if (this->idx < 8 && std::stoi(inputIndex) >= this->idx + 1) throw "Invalid input - Out of range\n";
}
