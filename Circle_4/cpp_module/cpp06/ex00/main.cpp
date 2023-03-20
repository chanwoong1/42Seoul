/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:07:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/20 21:20:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Invaild number of argument. Check it!" << std::endl;
    return (1);
  }
  ScalarConverter::convert(av[1]);
  return (0);
}
