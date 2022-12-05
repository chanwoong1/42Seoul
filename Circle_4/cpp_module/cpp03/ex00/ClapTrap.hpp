/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:00:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/05 20:34:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

#include <string>
#include <iostream>

class ClapTrap {
  private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

  public:
    ClapTrap( std::string name );
    ~ClapTrap();
    ClapTrap( const ClapTrap& clapTrap );
    ClapTrap& operator=( const ClapTrap& clapTrap );
    void attack( const std::string& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
};

#endif
