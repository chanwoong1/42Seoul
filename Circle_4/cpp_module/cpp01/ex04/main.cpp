/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:07:08 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/30 20:27:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ReadFile.hpp"

int main(int ac, char **av) {
  ReadFile readFile;
  try {
    if (ac != 4) throw "Error: Invalid number of arguments";
    readFile.openFile(av[1], av[2], av[3]);
    return (0);
  } catch (const char *error_message) {
    std::cout << error_message << std::endl;
    return (1);
  }
}