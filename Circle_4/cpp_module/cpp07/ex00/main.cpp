/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:32:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/29 17:12:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

void swapTest() {
  std::cout << "swap test start" << std::endl << std::endl;
  std::string A = "Hello";
  std::string B = "World";

  std::cout << "Type: string" << std::endl;
  std::cout << "Before swap" << std::endl;
  std::cout << "A : " << A << std::endl;
  std::cout << "B : " << B << std::endl << std::endl;

  swap(A, B);
  std::cout << "After swap" << std::endl;
  std::cout << "A : " << A << std::endl;
  std::cout << "B : " << B << std::endl << std::endl;

  int intA = 12345;
  int intB = 67890;

  std::cout << "Type: int" << std::endl;
  std::cout << "Before swap" << std::endl;
  std::cout << "intA : " << intA << std::endl;
  std::cout << "intB : " << intB << std::endl << std::endl;

  swap(intA, intB);
  std::cout << "After swap" << std::endl;
  std::cout << "intA : " << intA << std::endl;
  std::cout << "intB : " << intB << std::endl << std::endl;

  char charA = 'A';
  char charB = 'Z';

  std::cout << "Type: char" << std::endl;
  std::cout << "Before swap" << std::endl;
  std::cout << "charA : " << charA << std::endl;
  std::cout << "charB : " << charB << std::endl << std::endl;

  swap(charA, charB);
  std::cout << "After swap" << std::endl;
  std::cout << "charA : " << charA << std::endl;
  std::cout << "charB : " << charB << std::endl << std::endl;

  /* Mix type can not work this function. */
  // int mixA = 12345;
  // char mixB = 'A';

  // std::cout << "Type: mix" << std::endl;
  // std::cout << "Before swap" << std::endl;
  // std::cout << "mixA : " << mixA << std::endl;
  // std::cout << "mixB : " << mixB << std::endl;

  // swap(mixA, mixB);
  // std::cout << "After swap" << std::endl;
  // std::cout << "mixA : " << mixA << std::endl;
  // std::cout << "mixA : " << mixB << std::endl;
  std::cout << "swap test finish" << std::endl << std::endl;
}

void minTest() {
  std::cout << "min test start" << std::endl << std::endl;
  std::string A = "Hello";
  std::string B = "World";

  std::cout << "Type: string" << std::endl;
  std::cout << "A : " << A << std::endl;
  std::cout << "B : " << B << std::endl << std::endl;
  std::cout << "min(A, B) : " << min(A, B) << std::endl << std::endl;

  int intA = 67890;
  int intB = 12345;

  std::cout << "Type: int" << std::endl;
  std::cout << "intA : " << intA << std::endl;
  std::cout << "intB : " << intB << std::endl << std::endl;
  std::cout << "min(intA, intB) : " << min(intA, intB) << std::endl << std::endl;

  char charA = 'A';
  char charB = 'Z';

  std::cout << "Type: char" << std::endl;
  std::cout << "charA : " << charA << std::endl;
  std::cout << "charB : " << charB << std::endl;
  std::cout << "min(charA, charB) : " << min(charA, charB) << std::endl << std::endl;

  int sameA = 10;
  int sameB = 10;

  std::cout << "sameA address : " << &sameA << std::endl;
  std::cout << "sameB address : " << &sameB << std::endl;
  std::cout << "min(sameA, sameB) address : " << &min(sameA, sameB) << std::endl;

  /* Mix type can not work this function. */
  // int mixA = 12345;
  // char mixB = 'A';

  // std::cout << "Type: mix" << std::endl;
  // std::cout << "Before swap" << std::endl;
  // std::cout << "mixA : " << mixA << std::endl;
  // std::cout << "mixB : " << mixB << std::endl;
  // std::cout << "min(mixA, mixB) : " << min(mixA, mixB) << std::endl << std::endl;

  std::cout << "min test finish" << std::endl << std::endl;
}

void maxTest() {
  std::cout << "max test start" << std::endl << std::endl;
  std::string A = "Hello";
  std::string B = "World";

  std::cout << "Type: string" << std::endl;
  std::cout << "A : " << A << std::endl;
  std::cout << "B : " << B << std::endl << std::endl;
  std::cout << "max(A, B) : " << max(A, B) << std::endl << std::endl;

  int intA = 67890;
  int intB = 12345;

  std::cout << "Type: int" << std::endl;
  std::cout << "intA : " << intA << std::endl;
  std::cout << "intB : " << intB << std::endl << std::endl;
  std::cout << "max(intA, intB) : " << max(intA, intB) << std::endl << std::endl;

  char charA = 'A';
  char charB = 'Z';

  std::cout << "Type: char" << std::endl;
  std::cout << "charA : " << charA << std::endl;
  std::cout << "charB : " << charB << std::endl;
  std::cout << "max(charA, charB) : " << max(charA, charB) << std::endl << std::endl;

  int sameA = 10;
  int sameB = 10;

  std::cout << "sameA address : " << &sameA << std::endl;
  std::cout << "sameB address : " << &sameB << std::endl;
  std::cout << "max(sameA, sameB) address : " << &max(sameA, sameB) << std::endl;

  /* Mix type can not work this function. */
  // int mixA = 12345;
  // char mixB = 'A';

  // std::cout << "Type: mix" << std::endl;
  // std::cout << "Before swap" << std::endl;
  // std::cout << "mixA : " << mixA << std::endl;
  // std::cout << "mixB : " << mixB << std::endl;
  // std::cout << "max(mixA, mixB) : " << max(mixA, mixB) << std::endl << std::endl;

  std::cout << "max test finish" << std::endl << std::endl;
}

int main() {
  int a = 2;
  int b = 3;
  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

  std::cout << std::endl << std::endl << "Additional Test" << std::endl;
  swapTest();
  minTest();
  maxTest();
}