/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:53:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 17:54:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.hpp"
#include <string>

class HumanB {
  private:
    std::string _name;
    Weapon _type;

  public:
    HumanB( std::string name );
    ~HumanB();
    void attack( void );
    void setWeapon( Weapon type );
};

#endif