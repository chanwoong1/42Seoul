/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:27:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/06 13:22:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("value is not in this container");
	return iter;
}

#endif
