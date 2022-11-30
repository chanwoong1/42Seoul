/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadFile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:27:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/30 21:26:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_H_
#define READFILE_H_

#include <fstream>
#include <iostream>
#include <string>

class ReadFile {
  private:
    std::ifstream _ifs;
    std::ofstream _ofs;
    std::string _s1;
    std::string _s2;
    std::string _readLine;
    size_t      pos;
    void setArguments( const std::string fileName, const std::string s1, const std::string s2 );
    void isOpen( void );
    void isValidInput( void );
    void getLineInIfs( void );
    void replaceString( void );

  public:
    ReadFile();
    ~ReadFile();
    void openFile( const std::string fileName, const std::string s1, const std::string s2 );
};

#endif
