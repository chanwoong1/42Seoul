/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:53:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/04 23:09:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.hpp"
#include <string>

class HumanB {
  private:
    std::string _name;
    Weapon *_type;

  public:
    HumanB( const std::string &name );
    ~HumanB();
    void attack( void ) const;
    void setWeapon( Weapon *type );
};

#endif