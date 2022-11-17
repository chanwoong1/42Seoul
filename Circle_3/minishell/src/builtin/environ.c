/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "../main/helper.h"

bool	is_right_format(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (true);
	else
		return (false);
}

int	exec_export(char **arglist, char ***our_envp_ptr)
{
	char	**tmp_split;
	char	*tmp;

	if (arglist[1] == NULL)
		print_in_order(*our_envp_ptr);
	else if (!is_right_format(arglist[1][0]))
	{
		ft_putstr_fd("export: ", STDERR_FILENO);
		ft_putstr_fd(arglist[1], STDERR_FILENO);
		ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
		return (ERROR);
	}
	else if (ft_strchr(arglist[1], '=') != NULL)
	{
		tmp_split = ft_split(arglist[1], '=');
		tmp = arglist[1];
		arglist[1] = tmp_split[0];
		exec_unset(arglist, our_envp_ptr);
		arglist[1] = tmp;
		delete_strs(&tmp_split);
		add_to_envp(arglist[1], our_envp_ptr);
	}
	return (SUCCESS);
}

int	exec_env(char **arglist, char **our_envp)
{
	if (arglist[0] == NULL)
		return (ERROR);
	if (arglist[1] != NULL && arglist[1][0] == '-')
	{
		ft_putstr_fd("env: illegal option or argument", STDERR_FILENO);
		ft_putstr_fd(arglist[1], STDERR_FILENO);
		return (ERROR);
	}
	else
		print_strs(our_envp);
	return (SUCCESS);
}

static void	copy_to_envp(size_t	strs_count, char **arglist, \
		char **new_envp, char ***our_envp_ptr)
{
	size_t	i;
	size_t	j;
	char	**str_split;

	i = 0;
	j = i;
	str_split = NULL;
	strs_count = get_strs_count(*our_envp_ptr);
	while (i < strs_count)
	{
		str_split = ft_split((*our_envp_ptr)[i], '=');
		if (ft_strncmp(str_split[0], arglist[1], \
					ft_strlen(str_split[0]) + 1) != 0)
		{
			new_envp[j] = (*our_envp_ptr)[i];
			j++;
		}
		else
			free((*our_envp_ptr)[i]);
		delete_strs(&str_split);
		i++;
	}
}

int	exec_unset(char **arglist, char ***our_envp_ptr)
{
	char	**new_envp;
	size_t	strs_count;

	if (arglist[1] != NULL && arglist[1][0] == '-')
	{
		ft_putstr_fd("unset: illegal option ", STDERR_FILENO);
		ft_putstr_fd(arglist[1], STDERR_FILENO);
		return (ERROR);
	}
	else if (arglist[1] != NULL)
	{
		strs_count = get_strs_count(*our_envp_ptr);
		new_envp = ft_calloc(strs_count + 1, sizeof(*new_envp));
		copy_to_envp(strs_count, arglist, new_envp, our_envp_ptr);
		free(*our_envp_ptr);
		*our_envp_ptr = new_envp;
	}
	return (SUCCESS);
}
