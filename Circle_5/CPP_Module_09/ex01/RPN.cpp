#include "RPN.hpp"

/*
* A default constructor
*/
RPN::RPN() {}

RPN::RPN(char *av) {
  this->stringArgv = av;
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
RPN& RPN::operator=(const RPN& ref) {
  if (this != &ref) {
    this->stringArgv = ref.stringArgv;
    this->splitString = ref.splitString;
    this->rpn = ref.rpn;
  }
  return *this;
}

/*
* A destructor
*/
RPN::~RPN() {
}

void RPN::play() {
  try {
    split();
    calculate();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void RPN::split() {
  std::istringstream ss(this->stringArgv);
  std::string stringBuffer;
  std::stack<std::string> tmp;
  while (std::getline(ss, stringBuffer, ' ')) {
    if (stringBuffer.empty()) continue;
    tmp.push(stringBuffer);
  }

  this->numberOfValues = 0;
  while (!tmp.empty()) {
    this->splitString.push(tmp.top());
    validateInput(tmp.top());
    tmp.pop();
  }

  if (2 * this->numberOfValues - this->splitString.size() != 1) throw RPN::Error();
}

void RPN::validateInput(std::string s) {
  if (s.length() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
    return ;
  char *ptr = NULL;
  double value = std::strtod(s.c_str(), &ptr);
  if (value == 0.0 && !std::isdigit(s[0])) throw RPN::Error();
  if (*ptr && std::strcmp(ptr, "f")) throw RPN::Error();
  if (value < 0 || value >= 10) throw RPN::Error();
  ++this->numberOfValues;
}

bool RPN::isOperator(char op) {
  return (op == '+' || op == '-' || op == '*' || op == '/');
}

double RPN::calculator(double a, double b, char op) {
  if (op == '+') return (a + b);
  if (op == '-') return (a - b);
  if (op == '*') return (a * b);
  if (b == 0) throw RPN::Error();
  return (a / b);
}

void RPN::calculate() {
  while (!this->splitString.empty()) {
    std::string tmp = this->splitString.top();
    if (isOperator(tmp[0])) {
      if (this->rpn.size() < 2) throw RPN::Error();
      double a, b;
      b = this->rpn.top();
      this->rpn.pop();
      a = this->rpn.top();
      this->rpn.pop();
      this->rpn.push(this->calculator(a, b, tmp[0]));
      this->splitString.pop();
    }
    else {
      double value = std::strtod(this->splitString.top().c_str(), NULL);
      this->rpn.push(value);
      this->splitString.pop();
    }
  }
  std::cout << this->rpn.top() << std::endl;
}

const char* RPN::Error::what() const throw() {
  return "Error";
}
