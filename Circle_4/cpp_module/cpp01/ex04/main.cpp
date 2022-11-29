/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:07:08 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 11:34:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ReadFile.hpp"

int main(int ac, char **av) {
  ReadFile readFile;
  try {
    if (ac != 4) throw "Error: Invalid number of arguments";
    readFile.openFile(av[1]);
    // ReadFile::openFile(av[1]);
  } catch (const char *error_message) {
    std::cout << error_message << std::endl;
    return (1);
  }
  return (0);
}