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
#include <ctime>

#define SET_W  30

class PmergeMe {
  private:
    /* data */
    std::vector<int> originalData;
    std::vector<int> vectorData;
    std::list<int> listData;
    std::deque<int> dequeData;

    PmergeMe();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void printBefore();
    void printAfter();

    void vectorSort();
    void listSort();
    void dequeSort();

    void mergeInsertionSortVector(int left, int right, int k);
    void mergeInsertionSortList(int left, int right, int k);
    void mergeInsertionSortDeque(int left, int right, int k);

    void insertionSortVector(int left, int right);
    void insertionSortList(int left, int right);
    void insertionSortDeque(int left, int right);

    void mergeVector(int l, int m, int r);
    void mergeList(int l, int m, int r);
    void mergeDeque(int l, int m, int r);

    int getValueOfList(std::list<int> list, int idx);
    void setValueOfList(int idx, int value);

    int getValueOfDeque(std::deque<int> deque, int idx);
    void setValueOfDeque(int idx, int value);

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

    void sort();
};

#endif  //PmergeMe_HPP
