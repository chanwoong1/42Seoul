/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:18:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/28 11:35:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_HPP
#define Base_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#define SET_W  30

class Base {
  public:
    /*
    * A destructor
    */
    virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif  //Base_HPP
