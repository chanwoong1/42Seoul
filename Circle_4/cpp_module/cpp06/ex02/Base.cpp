/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:19:58 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/28 12:00:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate() {
  int random = std::time(nullptr) % 3;

  switch (random) {
    case 0:
      std::cout << "Create A" << std::endl;
      return new A();
    case 1:
      std::cout << "Create B" << std::endl;
      return new B();
    case 2:
      std::cout << "Create C" << std::endl;
      return new C();
  }
  return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Pointer B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Pointer C" << std::endl;
}

static void identifyRef(Base& p, const std::string& str) {
  try {
    if (str == "A")
      (void)dynamic_cast<A&>(p);
		if (str == "B")
      (void)dynamic_cast<B&>(p);
		if (str == "C")
      (void)dynamic_cast<C&>(p);
    std::cout << "Reference " << str << std::endl;
  } catch (std::exception&) {}
}

void identify(Base& p)
{
  identifyRef(p, "A");
  identifyRef(p, "B");
  identifyRef(p, "C");
}
