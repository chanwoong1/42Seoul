#include "RPN.hpp"

/*
* A default constructor
*/
RPN::RPN() {}

RPN::RPN(char *av) {
  try {
    split(av);
    calculate();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

/*
* A copy constructor
*/
RPN::RPN(const RPN& ref) {
  *this = ref;
}

/*
* A assignment operator overload
*/
RPN&	RPN::operator=(const RPN& ref) {
  if (this != &ref) {
    /* insert */
  }
  return *this;
}

/*
* A destructor
*/
RPN::~RPN() {
}

void RPN::split(char *av) {
  std::string stringTmp(av);
  std::istringstream ss(stringTmp);
  std::string stringBuffer;
  std::stack<std::string> tmp;
  while (std::getline(ss, stringBuffer, ' ')) {
    tmp.push(stringBuffer);
  }

  while (!tmp.empty()) {
    this->splitString.push(tmp.top());
    validateInput(tmp.top());
    tmp.pop();
  }
}

void RPN::validateInput(std::string s) {
  if (s.length() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) return ;
  if (s.length() == 1 && (s[0] >= '0' && s[0] <= '9')) return ;
  throw RPN::Error();
}

void RPN::calculate() {
  this->rpnSize = 0;
  while (!this->splitString.empty()) {
    std::string tmp = this->splitString.top();
    if (this->rpnSize < 2) {

    }
  }
}

const char* RPN::Error::what() const throw() {
  return "Error";
}
