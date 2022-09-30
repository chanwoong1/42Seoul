/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:30:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/30 11:19:45 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*cmd;

	while (1)
	{
		cmd = readline("minishell> ");
		if (!cmd)
			break ;
		printf("cmd : %s\n", cmd);
	}
	return (0);
}
