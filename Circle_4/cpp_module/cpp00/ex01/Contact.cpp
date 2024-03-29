/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:39:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 13:11:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(
  std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret
  ) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact() {
	*this = Contact("", "", "", "", "");
}

Contact::~Contact() {
}

std::string	Contact::GetFirstName() {
	return this->firstName;
}

std::string	Contact::GetLastName() {
	return this->lastName;
}

std::string	Contact::GetNickName() {
	return this->nickName;
}

std::string	Contact::GetPhoneNumber() {
	return this->phoneNumber;
}

std::string	Contact::GetDarkestSecret() {
	return this->darkestSecret;
}
