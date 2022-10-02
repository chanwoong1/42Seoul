/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:09:31 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 17:39:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int ac, char **argv, char **envp)
{
	char		*cmd;
	t_parse		*cmd_parse;
	t_shell		shell;

	// intro(); // 시작할 때 화면에 그림 띄우면 좋을듯 하다..
	if (ac != 1)
		error_exit("Don't input argument!!", 1);
	init_shell(&shell, argv, envp);
	while (1)
	{
		cmd_parse = (t_parse *)malloc(sizeof(t_parse));
		if (!cmd_parse)
			error_exit("malloc error of minishell, try one more time.", 1);
		cmd = readline("minishell> ");
		if (!cmd)
			break ;
		save_history(&shell, cmd, shell.idx);
		printf("%s", shell.history);
		// printf("cmd : %s\n", cmd);
		init_cmd_parse(&cmd_parse, &shell, cmd);
		// parse_cmd(cmd);
		// 인자 파싱해주는 함수 만들기
		// cmd마다 환경변수 찾아줘야하지않을까 ...
		// 명령어마다 자식프로세스 생성
		free(cmd);
		free(cmd_parse);
		shell.idx++;
	}
	system("leaks minishell");
	return (0);
}
