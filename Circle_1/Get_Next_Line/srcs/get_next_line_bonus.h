/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:58:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 16:06:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

typedef struct s_list
{
	int				fd_index;
	int				f_eof;
	char			*backup;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
ssize_t	ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2, size_t size_s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1, size_t n);
int		ft_lstnew(int fd, t_list **head);
t_list	*find_fd(int fd, t_list *node);
void	buf_clear(t_list *node, size_t idx, size_t len);
char	*read_buf(int fd, t_list *node);
void	free_node(t_list **head, int fd);

#endif