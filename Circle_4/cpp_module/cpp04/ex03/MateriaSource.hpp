/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:37:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/17 04:43:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    AMateria* _amateria[4];

  public:
    /*
    * A default constructor
    */
    MateriaSource();

    /*
    * A copy constructor
    */
    MateriaSource(const MateriaSource& ref);

    /*
    * A assignment operator overload
    */
    MateriaSource&	operator=(const MateriaSource& ref);

    /*
    * A destructor
    */
    ~MateriaSource();

    /*
    * Add it if you feel necessary additional member functions.
    */
    const AMateria* getAMateria(int idx) const;
    void learnMateria(AMateria* amateria);
    AMateria* createMateria(const std::string& type);
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //MateriaSource_HPP
