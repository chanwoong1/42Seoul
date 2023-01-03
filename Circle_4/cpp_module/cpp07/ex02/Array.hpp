/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:37:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/03 20:05:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
#define Array_HPP

#include <exception>

template <typename T>
class Array {
  private:
    /*
    * data
    TODO: You MUST use the operator new[] to allocate memory.
      ! Preventive allocation (allocating memory in advance) is forbidden. Your program must never access non-allocated memory.
    */
    T* _array;
    unsigned int _arraySize;

  public:
    /*
    * A default constructor
    TODO: Constuction with no parameter: Creates an empty array.
    */
    Array() : _array(NULL), _arraySize(0) {
    }

    /*
    TODO: Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
      ! Tip: Try to complie int * a = new int(); then display *a.
    */
    Array(unsigned int n) : _array(NULL), _arraySize(n) {
      if (this->_arraySize != 0)
        this->_array = new T[this->_arraySize];
    } 

    /*
    TODO: Construction by copy and assignment operator.
      ! In both class, modifying either the original array or its copy after copying musn't affect the other array.
    */
    Array(const Array& ref) : _array(NULL), _arraySize(ref.size()) {
      if (this->_arraySize != 0)
        this->_array = new T[this->_arraySize];
      for (unsigned int idx = 0; idx < this->_arraySize; ++idx)
        this->_array[idx] = ref[idx];
    }

    Array&	operator=(const Array& ref) {
      if (this != &ref) {
        this->_arraySize = ref.size();
        if (this->_arraySize != 0)
          this->_array = new T[this->_arraySize];
        for (unsigned int idx = 0; idx < this->_arraySize; ++idx)
          this->_array[idx] = ref[idx];
      }
      return *this;
    }

    /*
    TODO: Element can be accessed through the subscript operator: [ ].
      ! When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
    */
    T& operator[](unsigned int idx) {
      if (idx < 0 || idx > this->_arraySize - 1) throw OutOfBounds();
      return this->_array[idx];
    }

    const T& operator[](unsigned int idx) const {
      if (idx < 0 || idx > this->_arraySize - 1) throw OutOfBounds();
      return this->_array[idx];
    }

    /*
    TODO: When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
    */
    class OutOfBounds : public std::exception {
      public:
        const char* what() const throw() {
          return "Array - Out of range";
        }
    };
    
    /*
    * A destructor
    */
    ~Array() {
      if (this->_arraySize != 0)
        delete [] this->_array;
      this->_array = NULL;
      this->_arraySize = 0;
    }

    /*
    * Add it if you feel necessary additional member functions.
    TODO: A member function size() that returns the number of elements in the array. This member function takes no parameter and musn't modify the current instance.
    */
    unsigned int size() const {
      return this->_arraySize;
    }
};

#endif  //Array_HPP
