/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:39:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/19 19:08:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// WARN:  Exception throw from Form class need to be caught in main()!
	Bureaucrat jack("jack", 2);
	try
	{
		ShrubberyCreationForm scf("Home");
    std::cout << scf.getBeSigned() << std::endl;
    scf.execute(jack);
	}
	catch (std::exception& e)
	{
		std::cout << jack.getName() << " can't execute form because " << e.what() << "\n";
	}
	std::cout << "\n";

	// Bureaucrat peter("peter", 29);
	// try
	// {
	// 	ShrubberyCreationForm("Home").beSigned(peter).beExecuted(jack);
	// }
	// catch (Form::Exception& e)
	// {
	// 	std::cout << jack << " can't execute form because " << e.what() << "\n";
	// }
	// std::cout << "\n";


	// RobotomyRequestForm weapon1("Killer Robot - 1");
	// Bureaucrat("Paul", 5).signForm(weapon1).executeForm(weapon1);
	// std::cout << "\n";

	// RobotomyRequestForm weapon4("Killer Robot - 4");
	// Bureaucrat("Paul", 5).signForm(weapon1).executeForm(weapon1);
	// std::cout << "\n";

	// RobotomyRequestForm weapon2("Killer Robot - 2");
	// Bureaucrat("Ellie", 5).signForm(weapon2).executeForm(weapon2);
	// std::cout << "\n";


	// PresidentialPardonForm pardon("Jack the Ripper");
	// Bureaucrat("Biden", 1).signForm(pardon).executeForm(pardon);
	// std::cout << "\n";


	return (0);
}
