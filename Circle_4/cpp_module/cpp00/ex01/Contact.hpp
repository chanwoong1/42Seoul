/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:35:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 13:58:35 by chanwjeo         ###   ########.fr       */
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
  ~Contact();
	Contact(
    std::string firstName,
    std::string lastName,
    std::string nickName,
    std::string phoneNumber,
    std::string darkestSecret
  );
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
  std::string GetPhoneNumber();
  std::string GetDarkestSecret();
};

#endif
