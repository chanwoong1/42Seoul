/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:33:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 14:53:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <iostream>
#include <string>
#include <iomanip>

class WrongCat {
  private:
    /* data */

  public:
    /*
    * A default constructor
    */
    WrongCat();

    /*
    * A copy constructor
    */
    WrongCat(const WrongCat& ref);

    /*
    * A assignment operator overload
    */
    WrongCat&	operator=(const WrongCat& ref);

    /*
    * A destructor
    */
    ~WrongCat();

    /*
    * Add it if you feel necessary additional member functions.
    */

};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //WrongCat_HPP
