/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:34:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/28 18:45:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon {
  private:
    std::string _type;

  public:
    Weapon();
    Weapon( std::string type );
    ~Weapon();
    void setType( std::string type );
    std::string getType( void );
    
};

#endif
