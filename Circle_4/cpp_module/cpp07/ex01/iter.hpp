/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:44:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 19:42:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void iter(const T* array, std::size_t lengthOfArray, void (*f)(const T &)) {
  for (std::size_t idx = 0; idx < lengthOfArray; ++idx) {
    f(array[idx]);
  }
}

template <typename T>
void print(const T& arg) {
  std::cout << arg << "\t";
}

#endif
