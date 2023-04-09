/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:45:31 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/04/09 13:15:42 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  BitcoinExchange bitEx;
  bitEx.checkCsvFile();
	bitEx.checkInputFile(av[1]);
	bitEx.Bitcoin(av[1]);
}
