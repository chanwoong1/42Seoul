/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:01:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/28 10:55:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct Data {
  std::string name;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
  Data ptr;
  Data* convertPtr = NULL;

  ptr.name = "original data";
  convertPtr = deserialize(serialize(&ptr));
  std::cout << "ptr.name: " << ptr.name << std::endl << "convertPtr.name: " << convertPtr->name << std::endl;
  return 0;
}
