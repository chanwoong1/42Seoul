/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/11 21:35:17 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <cmath>
#include <iostream>

class Fixed {
  private:
    /*
    * An integer to store the fixed-point number value.
    * A static constant integer to store the number of fractinal bits. Its value will always be the integer literal 8.
    */
    int fixedPoint;
    static const int fractionalBits = 8;

  public:
    /*
    * A default constructor
      ! A constructor that takes a constant integer as a parameter.
      ! A constructor that takes a constant floating-point number as a parameter.
      ! It converts it to the corresponding fixed-point value. the fractional bits value is initialized to 8 like in ex00.
    * A copy constructor
    * A copy assignment operator overload
    * A destructor
    * A member function int getRawBits( void ) const;
      ! that returns the raw value of the fixed-point value.
    * A member function void setRawBits( int const raw );
      ! that sets the raw value of the fixed-point number.
    * A member function float toFloat( void ) const;
      ! that converts the fixed-point value to a floating-point value.
    * A member function int toInt( void ) const;
      ! that converts the fixed-point value to an integer value.
    */
    Fixed();
    explicit Fixed(const int v);
    explicit Fixed(const float v);
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

/*
  * Add the following function to the Fixed class files 
  * An overload of the insertion ( << ) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
*/
std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif