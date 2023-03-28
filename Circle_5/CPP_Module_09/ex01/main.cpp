/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:14:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/28 22:09:41 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void leaks() {
  system("leaks RPN");
}

int main(int ac, char **av) {
  atexit(leaks);
  if (ac != 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  RPN rpn(av[1]);
  return 0;
}
