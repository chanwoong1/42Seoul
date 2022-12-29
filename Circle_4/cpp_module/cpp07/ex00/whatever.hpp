/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:32:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/29 15:14:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T& min(T& a, T& b) {
  return (a >= b) ? b : a;
}

template <typename T>
T& max(T&a, T&b) {
  return (a <= b) ? b : a;
}