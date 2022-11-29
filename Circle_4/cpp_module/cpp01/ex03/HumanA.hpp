/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:42:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 09:01:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.hpp"
#include <string>

class HumanA {
  private:
    std::string _name;
    Weapon &_type;

  public:
    HumanA( const std::string name, Weapon *type );
    ~HumanA();
    void attack( void ) const;
};

#endif