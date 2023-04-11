/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:14:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/04/11 08:40:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void leaks() {
  system("leaks RPN");
}

int main(int ac, char **av) {
  atexit(leaks);
  if (ac != 2) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  RPN rpn(av[1]);
  rpn.play();
  return 0;
}
