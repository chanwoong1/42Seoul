/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:34:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 09:39:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl harl;

  std::cout << "Hi, I'm Harl. My complain is ..." << std::endl;
  std::cout << "DEBUG      : ";
  harl.complain("DEBUG");
  std::cout << "INFO       : ";
  harl.complain("INFO");
  std::cout << "WARNING    : ";
  harl.complain("WARNING");
  std::cout << "ERROR      : ";
  harl.complain("ERROR");
  std::cout << "DIRTY      : ";
  harl.complain("DIRTY");
  std::cout << "DEBUG,INFO : ";
  harl.complain("DEBUG,INFO");
  return (0);
}
