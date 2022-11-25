/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:39:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/25 21:17:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
// #include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  PhoneBook phoneBook = PhoneBook();
  std::string    command;

  std::cout << "My Awesome PhoneBook!" << std::endl;
	while (std::getline(std::cin, command))
	{
		if (command == "EXIT") {
			std::cout << "exit" << std::endl;
			break;
		}
		else if (command == "ADD")
			phoneBook.AddContact();
		else if (command == "SEARCH")
			phoneBook.SearchContact();
		else {
			std::cout << "It's not a valid command: " 
				<< command << std::endl;
		}
	}
	return (0);
}