# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/05 13:47:06 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c print_str.c print_num.c print_hex_num.c
BONUS = ft_printf_bonus.c ft_printf_utils_bonus.c \
		print_hex_num_bonus.c print_num_bonus.c print_num_precision_bonus.c \
		print_num_zero_bonus.c print_num_precision_2_bonus.c print_pointer_bonus.c \
		print_percent_bonus.c print_str_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS	= $(BONUS:c=o)

ifdef BONUSFLAG
	ALLOBJ 	= $(OBJS) $(OBJS_BONUS)
else
	ALLOBJ 	= $(OBJS)
endif

NAME = libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

AR = ar
ARFLAGS = rc

RM= rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(ALLOBJ)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(ARFLAGS) $@ $(ALLOBJ)

all : $(NAME)

bonus :
	make BONUSFLAG=1

clean :
	make -C libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re