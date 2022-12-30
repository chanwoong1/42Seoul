/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:44:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/30 12:41:42 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void iter(T* array, std::size_t lengthOfArray, void (*f)(T&)) {
  for (std::size_t idx = 0; idx < lengthOfArray; ++idx) {
    f(array[idx]);
  }
  std::cout << std::endl;
}

template <typename T>
void print(T& arg) {
  std::cout << arg << "\t";
}

#endif
