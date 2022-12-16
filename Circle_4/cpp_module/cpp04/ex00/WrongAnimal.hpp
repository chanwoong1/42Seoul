/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:39:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 11:49:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H_
#define WRONGANIMAL_H_

#include <iostream>
#include <string>

class WrongAnimal {
  protected:
    std::string _type;
  
  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    virtual ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;
};

std::ostream& operator<<(std::ostream& ofs, const WrongAnimal& wrongAnimal);

#endif
