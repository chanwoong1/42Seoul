# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/09/07 09:01:50 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = main.c utils.c parse.c

OBJS_FILES	= $(OBJS:c=o)

NAME = pipex
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

RM= rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS_FILES)
	@make all -C $(LIBFTDIR)/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_FILES) -L ./libft -lft

all : $(NAME)

bonus :
	make all

clean :
	make -C libft clean
	$(RM) $(OBJS_FILES)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
