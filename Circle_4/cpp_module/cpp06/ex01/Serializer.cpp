/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:20:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/03/20 00:32:40 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
* A default constructor
*/
Serializer::Serializer() {
}

/*
* A copy constructor
*/
Serializer::Serializer(const Serializer& ref) {
  *this = ref;
}

/*
* A assignment operator overload
*/
Serializer&	Serializer::operator=(const Serializer& ref) {
  if (this != &ref) {
    /* insert */
    *this = ref;
  }
  return *this;
}

/*
* A destructor
*/
Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
