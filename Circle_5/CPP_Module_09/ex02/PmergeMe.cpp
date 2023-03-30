#include "PmergeMe.hpp"

/*
* A default constructor
*/
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vec) {
  this->originalData = vec;
  this->vectorData = vec;
  this->listData.assign(vec.begin(), vec.end());
  this->dequeData.assign(vec.begin(), vec.end());
}

/*
* A copy constructor
*/
PmergeMe::PmergeMe(const PmergeMe& ref) {
  this->originalData = ref.originalData;
  this->vectorData = ref.vectorData;
  this->listData.assign(ref.listData.begin(), ref.listData.end());
  this->dequeData.assign(ref.dequeData.begin(), ref.dequeData.end());
}

/*
* A assignment operator overload
*/
PmergeMe&	PmergeMe::operator=(const PmergeMe& ref) {
  if (this != &ref) {
    /* insert */
    this->originalData = ref.originalData;
    this->vectorData = ref.vectorData;
    this->listData.assign(ref.listData.begin(), ref.listData.end());
    this->dequeData.assign(ref.dequeData.begin(), ref.dequeData.end());
  }
  return *this;
}

/*
* A destructor
*/
PmergeMe::~PmergeMe() {
}

void PmergeMe::sort() {
  printBefore();
  vectorSort();
  listSort();
  dequeSort();
  // for (std::list<int>::iterator it = this->listData.begin(); it != this->listData.end(); it++)
  //   std::cout << *it << " ";
  // std::cout << std::endl;
  // for (std::deque<int>::iterator it = this->dequeData.begin(); it != this->dequeData.end(); it++)
  //   std::cout << *it << " ";
  // std::cout << std::endl;
}

void PmergeMe::printBefore() {
  std::cout << "Before:\t";
  if (this->originalData.size() < 6) {
    for (size_t i = 0; i < this->originalData.size(); i++)
      std::cout << this->originalData[i] << " ";
    std::cout << std::endl;
  }
  else {
    for (size_t i = 0; i < 4; i++)
      std::cout << this->originalData[i] << " ";
    std::cout << "[...]" << std::endl;
  }
}

void PmergeMe::printAfter() {
  std::cout << "After:\t";
  if (this->vectorData.size() < 6) {
    for (size_t i = 0; i < this->vectorData.size(); i++)
      std::cout << this->vectorData[i] << " ";
    std::cout << std::endl;
  }
  else {
    for (size_t i = 0; i < 4; i++)
      std::cout << this->vectorData[i] << " ";
    std::cout << "[...]" << std::endl;
  }
}

/*
* Sort vector
*/
void PmergeMe::vectorSort() {
  clock_t start = clock();
  mergeInsertionSortVector(0, this->vectorData.size() - 1, 5);
  clock_t end = clock();
  printAfter();
  std::cout << "Time to process a range of " << std::setw(4) << this->vectorData.size() << " elements with std::vector : " << end - start << "ms" << std::endl;
}

void PmergeMe::insertionSortVector(int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = this->vectorData[i];
    int j = i - 1;
    while (j >= left && this->vectorData[j] > key) {
      this->vectorData[j + 1] = this->vectorData[j];
      j--;
    }
    this->vectorData[j + 1] = key;
  }
}

void PmergeMe::mergeVector(int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<int> left(n1), right(n2);

  for (int i = 0; i < n1; i++) left[i] = this->vectorData[l + i];
  for (int j = 0; j < n2; j++) right[j] = this->vectorData[m + 1 + j];

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      this->vectorData[k] = left[i];
      i++;
    } else {
      this->vectorData[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    this->vectorData[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    this->vectorData[k] = right[j];
    j++;
    k++;
  }
}

void PmergeMe::mergeInsertionSortVector(int left, int right, int k) {
  if (right - left + 1 <= k) {
    insertionSortVector(left, right);
  } else if (left < right) {
    int m = left + (right - left) / 2;
    mergeInsertionSortVector(left, m, k);
    mergeInsertionSortVector(m + 1, right, k);
    mergeVector(left, m, right);
  }
}

/*
* Sort list
*/
int PmergeMe::getValueOfList(std::list<int> list, int idx) {
  std::list<int> tmpList;

  tmpList.assign(list.begin(), list.end());
  std::list<int>::iterator iter = tmpList.begin();
  while (idx--) ++iter;
  return *iter;
}

void PmergeMe::setValueOfList(int idx, int value) {
  std::list<int>::iterator iter = this->listData.begin();
  while (idx--) ++iter;
  *iter = value;
}

void PmergeMe::listSort() {
  clock_t start = clock();
  mergeInsertionSortList(0, this->listData.size() - 1, 5);
  clock_t end = clock();
  std::cout << "Time to process a range of " << std::setw(4) << this->listData.size() << " elements with std::list : " << end - start << "ms" << std::endl;
}

void PmergeMe::insertionSortList(int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = this->getValueOfList(this->listData, i);
    int j = i - 1;
    while (j >= left && this->getValueOfList(this->listData, j) > key) {
      this->setValueOfList(j + 1, this->getValueOfList(this->listData, j));
      j--;
    }
    this->setValueOfList(j + 1, key);
  }
}

void PmergeMe::mergeList(int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  std::list<int> left, right;

  for (int i = 0; i < n1; i++) left.push_back(this->getValueOfList(this->listData, l + i));
  for (int j = 0; j < n2; j++) right.push_back(this->getValueOfList(this->listData, m + 1 + j));

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (this->getValueOfList(left, i) <= this->getValueOfList(right, j)) {
      this->setValueOfList(k, this->getValueOfList(left, i));
      i++;
    } else {
      this->setValueOfList(k, this->getValueOfList(right, j));
      j++;
    }
    k++;
  }

  while (i < n1) {
    this->setValueOfList(k, this->getValueOfList(left, i));
    i++;
    k++;
  }

  while (j < n2) {
    this->setValueOfList(k, this->getValueOfList(right, j));
    j++;
    k++;
  }
}

void PmergeMe::mergeInsertionSortList(int left, int right, int k) {
  if (right - left + 1 <= k) {
    insertionSortList(left, right);
  } else if (left < right) {
    int m = left + (right - left) / 2;
    mergeInsertionSortList(left, m, k);
    mergeInsertionSortList(m + 1, right, k);
    mergeList(left, m, right);
  }
}

/*
* Sort deque
*/
int PmergeMe::getValueOfDeque(std::deque<int> deque, int idx) {
  std::deque<int> tmpDeque;

  tmpDeque.assign(deque.begin(), deque.end());
  std::deque<int>::iterator iter = tmpDeque.begin();
  while (idx--) ++iter;
  return *iter;
}

void PmergeMe::setValueOfDeque(int idx, int value) {
  std::deque<int>::iterator iter = this->dequeData.begin();
  while (idx--) ++iter;
  *iter = value;
}

void PmergeMe::dequeSort() {
  clock_t start = clock();
  mergeInsertionSortDeque(0, this->dequeData.size() - 1, 5);
  clock_t end = clock();
  std::cout << "Time to process a range of " << std::setw(4) << this->dequeData.size() << " elements with std::deque : " << end - start << "ms" << std::endl;
}

void PmergeMe::insertionSortDeque(int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = this->getValueOfDeque(this->dequeData, i);
    int j = i - 1;
    while (j >= left && this->getValueOfDeque(this->dequeData, j) > key) {
      this->setValueOfDeque(j + 1, this->getValueOfDeque(this->dequeData, j));
      j--;
    }
    this->setValueOfDeque(j + 1, key);
  }
}

void PmergeMe::mergeDeque(int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  std::deque<int> left, right;

  for (int i = 0; i < n1; i++) left.push_back(this->getValueOfDeque(this->dequeData, l + i));
  for (int j = 0; j < n2; j++) right.push_back(this->getValueOfDeque(this->dequeData, m + 1 + j));

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (this->getValueOfDeque(left, i) <= this->getValueOfDeque(right, j)) {
      this->setValueOfDeque(k, this->getValueOfDeque(left, i));
      i++;
    } else {
      this->setValueOfDeque(k, this->getValueOfDeque(right, j));
      j++;
    }
    k++;
  }

  while (i < n1) {
    this->setValueOfDeque(k, this->getValueOfDeque(left, i));
    i++;
    k++;
  }

  while (j < n2) {
    this->setValueOfDeque(k, this->getValueOfDeque(right, j));
    j++;
    k++;
  }
}

void PmergeMe::mergeInsertionSortDeque(int left, int right, int k) {
  if (right - left + 1 <= k) {
    insertionSortDeque(left, right);
  } else if (left < right) {
    int m = left + (right - left) / 2;
    mergeInsertionSortDeque(left, m, k);
    mergeInsertionSortDeque(m + 1, right, k);
    mergeDeque(left, m, right);
  }
}
