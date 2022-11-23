/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:35:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/22 21:36:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
# define CONTACT_H_

#include <iostream>

class Contact {
  private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

  public:
  Contact();
	Contact(std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret);
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	~Contact();
};

#endif