/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:00:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/07 21:00:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

#include <string>
#include <iostream>

class ClapTrap {
  private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

  public:
    ClapTrap( std::string name );
    ~ClapTrap();
    ClapTrap( const ClapTrap& clapTrap );
    ClapTrap& operator=( const ClapTrap& clapTrap );
    std::string getName( void ) const ;
    unsigned int getHitPoints( void ) const ;
    unsigned int getEnergyPoints( void ) const ;
    unsigned int getAttackDamage( void ) const ;
    void attack( const std::string& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
};

#endif
