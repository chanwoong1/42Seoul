/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:30:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/30 15:34:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_exit(char *msg, int code)
{
	ft_putstr_fd(msg, 1);
	write(1, "\n", 1);
	exit(code);
}

void	here_doc(t_parse **cmd_parse, char *limiter)
{
	int		file;
	char	*line;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		error_exit("heredoc fail, try one more time.", 1);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			exit(1);
		if (!ft_strncmp(limiter, line, ft_strlen(limiter)) \
			&& ft_strlen(limiter) == (ft_strlen(line) - 1))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
}

void	is_fd(t_parse **cmd_parse, char **cmd_split, int i)
{
	int	i;

	if (!ft_strncmp(cmd_split[0], "<<", 2))
	{
		(*cmd_parse)->here_doc = 1;
		here_doc(cmd_split[1], cmd_parse);
		(*cmd_parse)->i_fd = open(".heredoc_tmp", O_RDONLY);
		if ((*cmd_parse)->i_fd < 0)
		{
			unlink(".heredoc_tmp");
			error_exit("fail with here_doc create, try one more time.", 1);
		}
	}
	else
	{
		(*cmd_parse)->i_fd = open(cmd_split[0], O_RDONLY);
		if ((*cmd_parse)->i_fd < 0)
			(*cmd_parse)->i_fd = 0;
	}
	i = 0;
	while (cmd_split[i])
		i++;
	if (!ft_strncmp(cmd_split[i - 2], ">>", 2))
		(*cmd_parse)->o_fd = open(cmd_split[i - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		(*cmd_parse)->o_fd = 1;
	if ((*cmd_parse)->o_fd < 0)
		error_exit("fail with here_doc open, try one more time.", 1);
}

void	init_cmd_parse(t_parse **cmd_parse, char **envp, char *cmd)
{
	char	**cmd_split;

	ft_memset(*cmd_parse, 0, sizeof(t_parse));
	(*cmd_parse)->envp = envp;
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		error_exit("malloc error of command, check your command.", 1);
	is_fd(cmd_parse, cmd_split);
}

int	main(int ac, char **argv, char **envp)
{
	char	*cmd;
	t_parse	*cmd_parse;

	// intro();
	// 시작할 때 화면에 그림 띄우면 좋을듯 하다..
	if (ac != 1)
		error_exit("Don't input argument!!", 1);
	(void)argv;
	while (1)
	{
		cmd_parse = (t_parse *)malloc(sizeof(t_parse));
		if (!cmd_parse)
			error_exit("malloc error of minishell, try one more time.", 1);
		cmd = readline("minishell> ");
		if (!cmd)
			break ;
		printf("cmd : %s\n", cmd);
		init_cmd_parse(&cmd_parse, envp, cmd);
		// parse_cmd(cmd);
		// 인자 파싱해주는 함수 만들기
		// cmd마다 환경변수 찾아줘야하지않을까 ...
		// 명령어마다 자식프로세스 생성
	}
	return (0);
}
