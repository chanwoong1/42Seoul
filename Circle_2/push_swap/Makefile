# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:38:32 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/25 10:47:20 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c utils.c split.c validate.c stack.c stack2.c \
		operations.c operations2.c operations3.c set_location.c \
		sort_34_args.c sort.c sort_rotate.c sort_utils.c

OBJS_FILES = $(SRCS:c=o)

SRCS = $(addprefix mandatory/, $(SRC))

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
