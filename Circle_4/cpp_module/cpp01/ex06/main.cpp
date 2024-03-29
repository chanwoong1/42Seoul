/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:34:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 15:50:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
  Harl harl;

  if (ac != 2) {
    std::cout << "Error: Invalid Number of Arguments" << std::endl;
    return (0);
  }
  harl.complain(av[1]);
  return (0);
}
