/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:34:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/04 22:01:42 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon {
  private:
    std::string _type;

  public:
    Weapon( const std::string &type );
    ~Weapon();
    void setType( const std::string &type );
    const std::string &getType( void ) const;
};

#endif
