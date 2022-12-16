/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:24:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 22:57:32 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  private:
    Brain* brain;
  
  public:
    Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    virtual ~Cat();

    void makeSound() const;
    Brain* getBrain() const;
};

#endif
