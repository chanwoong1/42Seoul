/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:39:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/23 12:27:13 by chanwjeo         ###   ########.fr       */
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

Contact::Contact()
{
	Contact("", "", "", "", "");
}

Contact::~Contact()
{
}

std::string	Contact::get_first_name()
{
	return this->firstName;
}

std::string	Contact::get_last_name()
{
	return this->lastName;
}

std::string	Contact::get_nickname()
{
	return this->nickName;
}