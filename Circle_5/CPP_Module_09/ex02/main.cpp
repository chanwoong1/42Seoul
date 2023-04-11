/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/04/11 08:40:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool validateInput(std::string s) {
  char *ptr = NULL;
  double value = std::strtod(s.c_str(), &ptr);
  if (value == 0.0 && !std::isdigit(s[0])) return false;
  if (*ptr && std::strcmp(ptr, "f")) return false;
  if (value < 0 || value > 2147483647) return false;
  return (value == static_cast<int>(value));
}

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  std::vector<int> originalData;
  int i = 1;
  while (i < ac) {
    std::string stringTmp(av[i]);
    std::istringstream ss(stringTmp);
    std::string stringBuffer;
    while (std::getline(ss, stringBuffer, ' ')) {
      if (!stringBuffer.empty() && validateInput(stringBuffer) == false) {
        std::cout << "Error" << std::endl;
        return 1;
      }
      if (stringBuffer.empty()) continue;
      originalData.push_back(static_cast<int>(strtod(stringBuffer.c_str(), NULL)));
    }
    ++i;
  }
  PmergeMe pm(originalData);
  pm.sort();
  return 0;
}
