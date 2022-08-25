# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:38:32 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/25 15:35:23 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = push_swap.c utils.c split.c validate.c stack.c stack2.c \
		operations.c operations2.c operations3.c set_location.c \
		sort.c sort_rotate.c sort_utils.c

OBJS_CHECKER = checker.c checker_utils.c checker_utils2.c \
				validate_checker.c split.c stack.c stack2.c \
				operations.c operations2.c operations3.c \
				get_next_line.c get_next_line_utils.c

SRCS = $(addprefix mandatory/, $(OBJS))
SRCS_BONUS = $(addprefix bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:c=o)

NAME = push_swap
RM = rm -rf

ifdef BONUS=1
	make -C ./bonus/ all
else
endif

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus :
	make BONUS=1

clean :
	$(RM) $(SRCS_FILES)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus
