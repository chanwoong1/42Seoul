/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/26 11:11:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contact[8];
    Contact CraeteContact();
    void    DisplaySearchList(std::string contactInfo);
    void    DisplayContact();
    void    ValidateInputIndex(std::string inputIndex);
    int     idx;

  public:
    PhoneBook();
    ~PhoneBook();
    void  AddContact();
    void  SearchContact();
};

#endif