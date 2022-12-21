/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:07:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/21 23:36:41 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int ac, char *av[]) {
  if (ac != 2) {
    std::cerr << "Invaild number of argument. Check it!" << std::endl;
    return (1);
  }

  Convert(av[1]);
  return (0);
}