/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:45:02 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/06 10:45:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
  Array<std::string> stringArray(6);
  stringArray[0] = "42";
  stringArray[1] = "Seoul";
  stringArray[2] = "cpp";
  stringArray[3] = "module";
  stringArray[4] = "07";
  stringArray[5] = "chanwjeo";
  std::cout << "stringArray size :\t" << stringArray.size() << std::endl;
  std::cout << "stringArray :\t";
  for (int i = 0; i < 6; ++i) {
    std::cout << "\t" << stringArray[i];
  }
  std::cout << std::endl << std::endl;

  Array<int> intArray(10);
  for (int i = 0; i < 10; ++i) {
    intArray[i] = i;
  }
  std::cout << "intArray size :\t\t" << intArray.size() << std::endl;
  std::cout << "intArray :\t";
  for (int i = 0; i < 10; ++i) {
    std::cout << "\t" << intArray[i];
  }
  std::cout << std::endl << std::endl;

  Array<char> charArray(10);
  for (int i = 0; i < 10; ++i) {
    charArray[i] = 'A' + i;
  }
  std::cout << "charArray size :\t" << charArray.size() << std::endl;
  std::cout << "charArray :\t";
  for (int i = 0; i < 10; ++i) {
    std::cout << "\t" << charArray[i];
  }
  std::cout << std::endl << std::endl;

  std::cout << "exception test" << std::endl;
  try {
    std::cout << "intArray[10] = 10 ->\t";
    intArray[10] = 10;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "intArray[-1] = 10 ->\t";
    intArray[-1] = 10;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}


// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }