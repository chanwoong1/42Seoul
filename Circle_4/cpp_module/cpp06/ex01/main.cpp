/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:01:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/20 00:31:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
  Data ptr;
  Data* convertPtr = NULL;
  Serializer serializer;

  ptr.name = "original data";
  convertPtr = serializer.deserialize(serializer.serialize(&ptr));

  std::cout << "ptr.name: " << ptr.name << std::endl << "convertPtr.name: " << convertPtr->name << std::endl;
  return 0;
}
