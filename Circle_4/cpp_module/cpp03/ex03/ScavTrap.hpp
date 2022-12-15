/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:13:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/15 11:59:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include "ClapTrap.hpp"

/*
* 클래스 상속
  ? 부모 클래스의 멤버 변수와 멤버 함수를 자식 클래스가 재사용하는 개념. 접근 제한자를 통해 상속의 범위 설정 가능
*/
class ScavTrap : virtual public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    virtual ~ScavTrap();
    
    /*
    * virtual function
      ! 자식 클래스에서 재정의 해주기 위해 다시 선언
    */
    void attack(const std::string& target);
    
    /*
    * ScavTrap will also have its own special capacity
    */
    void guardGate();
};

#endif
