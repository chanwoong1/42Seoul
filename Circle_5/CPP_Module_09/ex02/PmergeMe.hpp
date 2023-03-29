#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <sstream>

#define SET_W  30

class PmergeMe {
  private:
    /* data */
    std::vector<int> vectorData;
    std::list<int> listData;
    std::deque<int> dequeData;

    PmergeMe();
  public:
    /*
    * A default constructor
    */
    PmergeMe(std::vector<int> vec);

    /*
    * A copy constructor
    */
    PmergeMe(const PmergeMe& ref);

    /*
    * A assignment operator overload
    */
    PmergeMe&	operator=(const PmergeMe& ref);

    /*
    * A destructor
    */
    ~PmergeMe();

    /*
    * Add it if you feel necessary additional member functions.
    */

};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //PmergeMe_HPP
