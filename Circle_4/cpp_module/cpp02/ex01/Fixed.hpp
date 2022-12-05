/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/05 17:14:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>
#include <cmath>

class Fixed {
  private:
    int number;
    static const int bits = 8;
    const int fixedPoint = 8;
    const float floatFixedPoint = 8;
    
  public:
    Fixed();
    Fixed( const Fixed& fixed );
    ~Fixed();
    Fixed& operator=(const Fixed& fixed);
    int getRawBits( void ) const;
    void setRawBits(int const raw);
    float toFloat( void );
    int toInt( void );
    Fixed& operator<<(const Fixed& fixed);
};

#endif
