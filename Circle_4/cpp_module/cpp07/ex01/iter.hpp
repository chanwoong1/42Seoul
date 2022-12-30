/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:44:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/30 11:06:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(T& array, unsigned int lengthOfArray, void (*function)(T&)) {
  for (unsigned int idx = 0; idx < lengthOfArray; idx++) {
    function(array[idx]);
  }
}

template <typename T>
void printArray(T& array, unsigned int lengthOfArray) {
  for (unsigned int idx = 0; idx < lengthOfArray; idx++) {
    std::cout << "array[" << idx << "] : " << array[idx] << std::endl;
  }
}

template <typename T>
void multiple2(T& n) {
  n *= 2;
}
