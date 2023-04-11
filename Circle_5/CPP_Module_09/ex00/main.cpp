/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:45:31 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/04/11 09:24:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }
  BitcoinExchange bitEx;
  bitEx.play(av[1]);
}
