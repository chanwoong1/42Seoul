/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/12 10:33:54 by chanwjeo         ###   ########.fr       */
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
    */
    Fixed();

    /*
    ? int형 생성자는 정해진 비트 수 만큼 비트 쉬프트 연산을 해서 저장해준다.
    */
    explicit Fixed(const int value);
    
    /*
    ? float 생성자는 float형이 비트연산이 불가능하기 때문에 num * (1 << bits) 형식으로 저장한다.
    ? 또한, 42.42 * 256을 저장할 때, 10859.52를 소숫점 아래 값이 사라지므로 조금 더 근사치를 저장하기 위해 roundf 함수를 사용해준다.
    */
    explicit Fixed(const float value);
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    /*
    * A member function float toFloat( void ) const;
      ! that converts the fixed-point value to a floating-point value.
    */
    float toFloat(void) const;

    /*
    * A member function int toInt( void ) const;
      ! that converts the fixed-point value to an integer value.
    */
    int toInt(void) const;
};

/*
* Add the following function to the Fixed class files 
* An overload of the insertion ( << ) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
? output stream 객체에 대한 연산자 오버로딩이기 때문에 클래스 밖에 선언해준다.
? ostream 객체인 ofs에 부동 소수점 값을 입력해준다.
*/
std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);

#endif