/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:37:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/29 17:54:28 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H_
#define TEST_H_

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class TestClass {
  private:
    int total;
    int success;
    int failure;
  
  public:
    TestClass();
    ~TestClass();
    void addTotal();
    void addSuccess();
    void addFailure();
};

#endif