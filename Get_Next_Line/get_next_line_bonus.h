/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:58:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/28 21:37:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   1024
# endif

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;	
}					t_list;

char	*get_next_line(int fd);
int		ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);

#endif
