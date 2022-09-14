# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/09 14:38:22 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = ft_printf.c ft_printf_utils.c \
		print_hex_num.c print_hex_num_2.c \
		print_num.c print_num_precision.c print_num_precision_2.c \
		print_zero.c print_zero_2.c\
		print_pointer.c print_percent.c print_str.c

OBJS_FILES	= $(OBJS:c=o)

NAME = libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

AR = ar
ARFLAGS = rc

RM= rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS_FILES)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_FILES)

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
