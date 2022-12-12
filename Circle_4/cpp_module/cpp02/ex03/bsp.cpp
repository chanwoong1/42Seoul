/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/13 00:30:26 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point operator-(const Point& point1, const Point& point2) {
  return Point(
      (point1.getX() - point2.getX()).toFloat(),
      (point1.getY() - point2.getY()).toFloat());
}

Fixed	operator*(const Point& point1, const Point& point2)
{
	return Fixed(
    point1.getX() * point2.getY() -
    point1.getY() * point2.getX());
}

bool operator~(const Fixed& fixed)
{
	return (fixed > Fixed(0));
}

/*
* 벡터의 외적을 이용해 점의 위치를 판단할 수 있다.
  ! 외적을 구하는 공식은 점 a와 b의 (x, y, z) 좌표를 통해 구할 수 있는데, 이 문제에서는 2차원 평면이므로 계산이 굉장히 간결해진다.
  ! 점 a의 (x, y, z) 좌표를 (ax, ay, az)라고 하고, 점 b도 마찬가지로 적용해 (bx, by, bz)라고 한다면 외적의 공식은 (ay*bz - az*by, az*bx - ax*bz, ax*by - ay*bx)이다.
  ! bsp에 주어지는 4개의 점은 모두 2차원 평면에 위치하므로 z = 0으로 대입해주면 (0, 0, ax*by - ay*bx)가 외적이 되고, ax*by - ay*bx를 이 함수의 주요 값으로 활용한다.
  ? bsp 내부의 선언을 통해 총 6개의 Point 클래스를 선언해준다. 이것은 각각 평면에서 벡터로 활용된다.
  ? 벡터를 구했다면, * 연산자 오버로딩을 통해 외적을 구해줄 수 있다.
  ? 밑의 조건문을 만족한다면 3개의 벡터의 한쪽 방향에 점이 위치한다는 뜻으로, 삼각형 내부에 점이 위치함을 알 수 있다.
  ? 이 조건을 만족하지 않으면 삼각형 내부에 점이 위치하는 것이다.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
  Point ab = a - b;
  Point ap = a - point;

  Point bc = b - c;
  Point bp = b - point;
  
  Point ca = c - a;
  Point cp = c - point;

  if ((~(ab * bp) && ~(bc * cp) && ~(ca * ap))
    || (!(~(ab * bp)) && !(~(bc * cp)) && !(~(ca * ap))))
    return true;
  return false;
}
