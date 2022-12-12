/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:00:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/13 03:05:45 by chanwjeo         ###   ########.fr       */
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
    /*
    * A default constructor
    * param: std::string name
    TODO: Initialize private parameters [ _hitPoints(10), _energyPoints(10), _attackDamage(0) ]
    ! The constructor must also display a message.
    */
    ClapTrap( std::string name );

    /*
    * A copy constructor
    */
    ClapTrap( const ClapTrap& clapTrap );
    
    /*
    * A copy assignment operator overload
    */
    ClapTrap& operator=( const ClapTrap& clapTrap );
    
    /*
    * A destructor
    ! The destructor must also display a message.
    */
    ~ClapTrap();
    
    /*
    TODO: Add the following public member functions so the ClapTrap looks more realistic
    ! When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
    ! When ClapTrap repairs itself, it gets <amount> hit points back.
    ! Attacking and repairing cost 1 energy point each.
    ! Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
    */
    std::string getName( void ) const ;
    unsigned int getHitPoints( void ) const ;
    unsigned int getEnergyPoints( void ) const ;
    unsigned int getAttackDamage( void ) const ;

    /*
    TODO: Display a message to describe what happens.
    * example: ClapTrap <name> attacks <target>, causing <damage> points of damage!
    */
    void attack( const std::string& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
};

#endif
