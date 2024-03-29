/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:05:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/03 20:34:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>
#include <iostream>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie( std::string name );
    ~Zombie();
    void announce( void );
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif