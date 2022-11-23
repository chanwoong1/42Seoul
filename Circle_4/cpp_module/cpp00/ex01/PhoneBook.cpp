/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:30:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/23 12:49:17 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : idx(0) {
}

PhoneBook::~PhoneBook() {
}

Contact PhoneBook::CraeteContact() {
  Contact newContact = Contact("12345", "12345", "12345", "12345", "12345");

  return newContact;
}

std::string PhoneBook::AddContact() {
  std::string    command;


  std::cout << "first name> ";
  std::cout << "last name> ";
  std::cout << "nick name> ";
  std::cout << "phone number> ";
  std::cout << "darkest secret> ";
  return command;
}