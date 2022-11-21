/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:30:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/21 11:36:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../libft/include/libft.h"
#include "../main/minishell.h"

extern int	g_is_sig_interupt;
/* how exit() work with argument:
** 1) atoll(alpha to longlong)
** 1-1) if over/underflow occurs, it's not a number.
** 2) cast into unsigned char
*/

static bool	get_status(char *str, int *status)
{
	int					neg;
	unsigned long long	num;
	size_t				i;

	i = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((neg == -1 && num > (unsigned long long)LLONG_MIN)
			|| (neg == 1 && num > (unsigned long long)LLONG_MAX))
			return (false);
		i++;
	}
	if (str[i] == '\0')
	{
		*status = neg * num;
		return (true);
	}
	return (false);
}

/* exit [n]: exit with status of n.
** 1. no [n]: exit with exit status of last command.
** 2-1. [n] more than 1: command exit status 1. !!exit fail!!
** 2-2. [n] is not number: exit(255).
*/
int	exec_exit(char **arglist, char **our_envp, t_shell_config *config)
{
	int	status;

	(void)our_envp;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (arglist[1] == NULL)
		status = config->last_cmd_wstatus;
	else if (get_status(arglist[1], &status) == false)
	{
		ft_putstr_fd("orsh: exit: ", STDERR_FILENO);
		ft_putstr_fd(arglist[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	else if (arglist[2] != NULL)
	{
		ft_putstr_fd("orsh: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (g_is_sig_interupt == true)
		exit(1);
	else if (WIFSIGNALED(status))
		exit(WTERMSIG(status) + 128);
	else
		exit(WEXITSTATUS(status));
}
