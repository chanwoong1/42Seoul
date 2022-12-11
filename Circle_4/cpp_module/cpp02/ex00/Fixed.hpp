/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/11 20:12:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed {
  private:
    /*
    * An integer to store the fixed-point number value.
    * A static constant integer to store the number of fractinal bits. Its value will always be the integer literal 8.
    */
    int number;
    static const int bits = 8;
    
  public:
    /*
    * A default constructor
    * A copy constructor
    * A copy assignment operator overload
    * A destructor
    * A member function int getRawBits( void ) const;
      ! that returns the raw value of the fixed-point value.
    * A member function void setRawBits( int const raw );
      ! that sets the raw value of the fixed-point number.
    */
    Fixed();
    Fixed( const Fixed& fixed );
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits(int const raw);
};

#endif
