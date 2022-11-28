/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:54:17 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 17:27:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string	*stringPTR = &str;
	std::string	&stringREF = str;

  std::cout << "Print memory address of string" << std::endl;
  std::cout << "string memory address : " << &str << std::endl;
  std::cout << "stringPTR memory address : " << stringPTR << std::endl;
  std::cout << "stringREF memory address : " << &stringREF << std::endl;

  std::cout << std::endl << "Print value of string" << std::endl;
  std::cout << "string value : " << str << std::endl;
  std::cout << "stringPTR value : " << *stringPTR << std::endl;
  std::cout << "stringREF value : " << stringREF << std::endl;
  return (0);
}