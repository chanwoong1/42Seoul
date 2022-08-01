/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:47:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 11:46:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_valid_argv(char **argv)
{

}

int	ft_printf(const char *format, ...)
{
	
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (-1);
	if (!(is_valid_argv(argv)))	// argv가 적합한지 확인 
		return (-1);

	ft_printf(argv);

}

