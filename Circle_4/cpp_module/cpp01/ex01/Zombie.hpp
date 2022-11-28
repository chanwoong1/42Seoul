/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:05:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 16:50:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie();
    void announce( void );
    void setName( std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif