/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/23 12:30:06 by chanwjeo         ###   ########.fr       */
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
    int     idx;

  public:
    PhoneBook();
    ~PhoneBook();
    std::string  AddContact();
}

#endif