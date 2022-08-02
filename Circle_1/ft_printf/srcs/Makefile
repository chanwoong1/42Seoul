# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/02 13:27:29 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c print_c.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

AR = ar
ARFLAGS = -rcs

RM= rm -rf

%c : %o
	$(CC) $(CFLAGS) $^ -o $@
all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft all
	cp libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re