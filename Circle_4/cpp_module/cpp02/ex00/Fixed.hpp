/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/12 10:26:06 by chanwjeo         ###   ########.fr       */
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
    ? number에는 고정 소수점을 저장하고, bits에는 상수 8을 저장할 것이다.
    */
    int number;
    static const int bits = 8;
    
  public:
    /*
    * A default constructor
    */
    Fixed();
    
    /*
    * A copy constructor
    ? 복사 생성자는 같은 클래스의 레퍼런스를 인자로 받아, 새로운 클래스를 만들어 반환한다.
    ? 깊은 복사를 하기 때문에, 원본 객체와 같은 값을 가지지만 다른 주소 값을 가지게 된다.
    ! 깊은 복사 : '실제 값'을 새로운 메모리 공간에 복사
    ! 얕은 복사 : '주소 값'을 복사
    */
    Fixed(const Fixed& fixed);
    
    /*
    * A copy assignment operator overload
    ? 할당 연산자는 a=b의 형태의 동작에서 b를 인자로 받아 a에 대한 참조를 반환하도록 만든다.
    ! 직접 구현을 하지 않아도 컴파일러가 알아서 만들어주지만, 자신이 의도한대로 동작하지 않을 수 있으므로 직접 구현하는것이 좋다.
    */
    Fixed& operator=(const Fixed& fixed);
    
    /*
    * A destructor
    */
    ~Fixed();
    
    /*
    * A member function int getRawBits( void ) const;
      ! that returns the raw value of the fixed-point value.
    */
    int getRawBits(void) const;
    
    /*
    * A member function void setRawBits( int const raw );
      ! that sets the raw value of the fixed-point number.
    */
    void setRawBits(int const raw);
};

#endif
