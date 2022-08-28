# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 14:43:29 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/28 16:28:50 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = push_swap.c utils.c utils2.c split.c validate.c stack.c stack2.c \
		operations.c operations2.c operations3.c set_location.c \
		sort.c sort_rotate.c sort_utils.c

OBJS_CHECKER = checker.c checker_utils.c checker_utils2.c checker_utils3.c\
				validate_checker.c split.c stack.c stack2.c \
				operations.c operations2.c operations3.c \
				get_next_line.c get_next_line_utils.c

SRCS = $(addprefix mandatory/, $(OBJS))
SRCS_BONUS = $(addprefix bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:c=o)
SRCS_BONUS_FILES = $(SRCS_BONUS:c=o)

MAND_DIR = mandatory
BONUS_DIR = bonus

NAME = push_swap
BONUS = checker
RM = rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(SRCS_BONUS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(SRCS_FILES)
	$(RM) $(SRCS_BONUS_FILES)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus
