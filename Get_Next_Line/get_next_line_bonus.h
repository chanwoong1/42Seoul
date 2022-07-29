/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:58:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 11:02:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

typedef struct s_list
{
	int				fd_index;
	int				i_eof;
	char			*buff;
	struct s_list	*next;
}	t_list;

ssize_t	ft_find_line(char *buff);
t_list	*ft_fd_find(int fd, t_list *node);
void	ft_clear_buf(t_list *node, size_t i_lf, size_t len);
char	*ft_get_line(int fd, t_list *node);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	ft_node_clear(t_list **head, int fd);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
int		ft_new_node(int fd, t_list **head);
char	*ft_strndup(char *s1, size_t n);

#endif

// #ifndef GET_NEXT_LINE_BONUS_H
// # define GET_NEXT_LINE_BONUS_H

// # include <unistd.h>
// # include <stdlib.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE   1024
// # endif

// typedef struct s_list
// {
// 	int				fd;
// 	char			*backup;
// 	struct s_list	*next;	
// }					t_list;

// char	*get_next_line(int fd);
// int		ft_strchr(char *s);
// char	*ft_strjoin(char *s1, char *s2);
// int		ft_strlen(const char *s);

// #endif
