# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/02 20:07:36 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c print_str.c print_num.c print_hex_num.c
OBJS = $(SRCS:.c=.o)

NAME = ft_printf.a

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