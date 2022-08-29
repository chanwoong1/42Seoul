# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 14:43:29 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/29 08:55:48 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= main.c



OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		cc -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		# make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		# rm -f $(LIBFT_LIB)
		# make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus