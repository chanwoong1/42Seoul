/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/22 21:18:48 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    int j;
    for (int i = 1; i < ac; i++) {
      j = 0;
      while (av[i][j]) {
        std::cout << static_cast<char>(toupper(av[i][j]));
        j++;
      }
    }
  }
}