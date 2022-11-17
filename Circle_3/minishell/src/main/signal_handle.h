/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:03:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLE_H
# define SIGNAL_HANDLE_H

# include "signal_handle.h"
# include "minishell.h"

void	*new_pid(pid_t pid);
void	del_pid(void *content);

/* Waits every pids in config->pid_list.
 * then saves wstatus of last_cmd_pid to config->last_cmd_wstatus */
void	wait_every_pid(t_shell_config *config);

#endif /* SIGNAL_HANDLE_H */
