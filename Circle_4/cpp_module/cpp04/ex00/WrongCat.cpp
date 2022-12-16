/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:33:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 17:33:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
* A default constructor
*/
WrongCat::WrongCat()
{
  std::cout << std::setw(15) << "[WrongCat] " << "create!!" << std::endl;
}


/*
* A copy constructor
*/
WrongCat::WrongCat(const WrongCat& ref)
{
  *this=ref;
  std::cout << std::setw(15) << "[WrongCat] " << "copy!!" << std::endl;
}

/*
* A assignment operator overload
*/
WrongCat&	WrongCat::operator=(const WrongCat& ref)
{
  *this=ref;
  std::cout << std::setw(15) << "[WrongCat] " << "operator=!!" << std::endl;
  return (*this);
}

/*
* A destructor
*/
WrongCat::~WrongCat()
{
  std::cout << std::setw(15) << "[WrongCat] " << "delete!!" << std::endl;
}
