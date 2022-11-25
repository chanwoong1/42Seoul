/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:30:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/25 21:36:47 by chanwjeo         ###   ########.fr       */
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
  std::cin >> firstName;
  std::cout << "last name> ";
  std::cin >> lastName;
  std::cout << "nick name> ";
  std::cin >> nickName;
  std::cout << "phone number> ";
  std::cin >> phoneNumber;
  std::cout << "darkest secret> ";
  std::cin >> darkestSecret;
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

  for (int i = 0; i < idx; i++) {
    std::cout << "│   " << (i + 1) % 8 << "   │";
    DisplaySearchList(contact[i].GetFirstName());
    DisplaySearchList(contact[i].GetLastName());
    DisplaySearchList(contact[i].GetNickName());
    std::cout << "\n";
  }
  std::cout << "└───────┴────────────┴────────────┴────────────┘" << std::endl;
  std::cout << std::endl << "Input index> ";

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
  int inputIndex;

  std::cin >> inputIndex;
  std::cout << "first name : " << contact[inputIndex].GetFirstName << std::endl;
  std::cout << "first name : " << contact[inputIndex].GetFirstName << std::endl;
  std::cout << "first name : " << contact[inputIndex].GetFirstName << std::endl;
}