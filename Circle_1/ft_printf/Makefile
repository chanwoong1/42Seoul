# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/09 13:17:23 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = ft_printf_bonus.c ft_printf_utils_bonus.c \
		print_hex_num_bonus.c print_num_bonus.c print_num_precision_bonus.c \
		print_num_zero_bonus.c print_num_precision_2_bonus.c print_pointer_bonus.c \
		print_percent_bonus.c print_str_bonus.c

OBJS_FILES	= $(BONUS:c=o)

NAME = libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

AR = ar
ARFLAGS = rc

RM= rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS_FILES)
	make -C $(LIBFTDIR)cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	
	$(AR) $(ARFLAGS) $@ $(OBJS_FILES)

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