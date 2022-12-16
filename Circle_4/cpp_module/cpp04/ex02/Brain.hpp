/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:39:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/16 19:44:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Brain {
  private:
    /*
    * An array of 100 std::string called ideas.
    */
    std::string ideas[100];

  public:
    /*
    * A default constructor
    */
    Brain();

    /*
    * A copy constructor
    */
    Brain(const Brain& ref);

    /*
    * A assignment operator overload
    */
    Brain&	operator=(const Brain& ref);

    /*
    * A destructor
    */
    ~Brain();

    /*
    * Add it if you feel necessary additional member functions.
    */
    std::string getIdeas(int n) const;
    void setIdeas(std::string idea, int n);
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //Brain_HPP
