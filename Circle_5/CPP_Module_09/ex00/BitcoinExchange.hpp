#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <cmath>
#include <map>

#define MAX 2147483647
#define TRUE 1
#define FALSE 0

class BitcoinExchange {
  private:
    /* data */
    std::map<std::string, float> bitcoinData;

    int validateDate(std::string s);
    int validateInput(std::string s);
    void checkCsvFile();
    void checkInputFile(char *file);
    void bitcoin(char *file);
    void checkInfo(std::string);
    int checkDate(const std::string&);
    int checkValue(const std::string&);
    void printBit(std::string date, float n);
  public:
    /*
    * A default constructor
    */
    BitcoinExchange();

    /*
    * A copy constructor
    */
    BitcoinExchange(const BitcoinExchange& ref);

    /*
    * A assignment operator overload
    */
    BitcoinExchange&	operator=(const BitcoinExchange& ref);

    /*
    * A destructor
    */
    ~BitcoinExchange();

    /*
    * Add it if you feel necessary additional member functions.
    */
    void play(char *file);

    class Error : public std::exception {
      public:
        const char* what() const throw();
    };
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //BitcoinExchange_HPP
