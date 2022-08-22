# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:38:32 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/22 11:57:33 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = main.c utils.c split.c validate.c stack.c stack2.c \
		operations.c operations2.c operations3.c \
		sort_34_args.c sort.c sort2.c get_astack_location.c

OBJS_FILES	= $(OBJS:c=o)

NAME = push_swap
RM = rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus :
	make all

clean :
	$(RM) $(OBJS_FILES)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
