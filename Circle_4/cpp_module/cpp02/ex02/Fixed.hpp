/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:52:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/09 18:15:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <cmath>
#include <iostream>

class Fixed {
  private:
    int fixedPoint;
    static const int fractionalBits = 8;

  public:
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed();
    ~Fixed();
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    bool operator>(const Fixed& f);
    bool operator<(const Fixed& f);
    bool operator>=(const Fixed& f);
    bool operator<=(const Fixed& f);
    bool operator==(const Fixed& f);
    bool operator!=(const Fixed& f);
    explicit Fixed(const int v);
    explicit Fixed(const float v);
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif