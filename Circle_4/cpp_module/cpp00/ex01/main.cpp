/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:39:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 12:27:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main() {
  PhoneBook phoneBook = PhoneBook();
  std::string    command;

  std::cout << "My Awesome PhoneBook!" << std::endl;
  std::cout << "command> ";
	while (std::getline(std::cin, command))
	{
		if (command == "EXIT") {
			std::cout << "exit" << std::endl;
			break;
		}
		else if (command == "ADD") {
      phoneBook.AddContact();
      std::cout << "command> ";
    }
		else if (command == "SEARCH") {
			phoneBook.SearchContact();
      std::cout << "command> ";
    }
		else {
			std::cout << "Invalid input - Command\n\n";
      std::cout << "command> ";
		}
	}
  if (std::cin.eof()) {
    std::cout << "Enter EOF. Program Exit." << std::endl;
    return (0);
  }
	return (0);
}
