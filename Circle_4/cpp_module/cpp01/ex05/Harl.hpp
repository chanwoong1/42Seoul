/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:34:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/30 22:05:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H_
#define HARL_H_

#include <iostream>
#include <string>

class Harl {
  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

  public:
    Harl();
    ~Harl();
    void complain( std::string level );
};

#endif