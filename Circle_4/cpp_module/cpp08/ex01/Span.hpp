/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:53:14 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 01:16:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <new>

#define SET_W  30

class Span {
  private:
    /* data */
    std::vector<int> _vector;

    Span();
  public:
    /*
    * A default constructor
    */
    Span(unsigned int N);

    /*
    * A copy constructor
    */
    Span(const Span& ref);

    /*
    * A assignment operator overload
    */
    Span&	operator=(const Span& ref);

    /*
    * A destructor
    */
    ~Span();

    /*
    * Add it if you feel necessary additional member functions.
    */
    std::size_t shortestSpan();
    std::size_t longestSpan();
    const std::vector<int>& getVector() const;
    void addNumber(int num);

    /*
    TODO: Implement a member function to add many numbers to your Span in one call.
    */
    template <typename T>
    void addManyNumbers(T& container) {
      if (std::distance(container.begin(), container.end()) > static_cast<int>(this->_vector.capacity() - this->_vector.size())) throw CanNotStoreNumber();
      typename T::iterator iter = container.begin();
      while (iter != container.end()) {
        this->_vector.push_back(*iter);
        ++iter;
      }
    }
    
    /*
    * Exception Class
    */
    class CanNotStoreNumber : public std::exception {
      public:
        const char* what() const throw();
    };

    class NotEnoughElement : public std::exception {
      public:
        const char* what() const throw();
    };
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //Span_HPP
