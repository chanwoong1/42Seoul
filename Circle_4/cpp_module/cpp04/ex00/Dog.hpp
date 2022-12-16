/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:24:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 10:55:30 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    virtual ~Dog();

    void makeSound() const;
};

#endif
