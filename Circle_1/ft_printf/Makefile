# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/02 14:38:22 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = srcs
SRCS = $(SRC)/ft_printf.c $(SRC)/print_c.c
OBJS = $(SRCS:.c=.o)

NAME = printf

AR = ar
ARFLAGS = -rcs

RM= rm -rf

%c : %o
	$(CC) $(CFLAGS) $< -o $@
all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) libft/libft.a $(OBJS) -o $(NAME)

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re