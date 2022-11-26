/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/26 17:56:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else {
    for (int i = 1; i < ac; i++) {
      for (int j = 0; av[i][j]; j++)
        std::cout << static_cast<char>(toupper(av[i][j]));
    }
    std::cout << std::endl;
  }
}
