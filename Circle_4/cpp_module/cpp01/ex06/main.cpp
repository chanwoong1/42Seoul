/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:34:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 10:21:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl harl;

  std::cout << "Hi, I'm Harl. My complain is ..." << std::endl;
  std::cout << std::endl << "[ DEBUG ]" << std::endl;
  harl.complain("DEBUG");
  std::cout << std::endl << "[ INFO ]" << std::endl;
  harl.complain("INFO");
  std::cout << std::endl << "[ WARNING ]" << std::endl;
  harl.complain("WARNING");
  std::cout << std::endl << "[ ERROR ]" << std::endl;
  harl.complain("ERROR");
  std::cout << std::endl << "[ DIRTY ]" << std::endl;
  harl.complain("DIRTY");
  std::cout << std::endl << "[ DEBUG,INFO ]" << std::endl;
  harl.complain("DEBUG,INFO");
  return (0);
}
