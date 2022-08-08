# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:25:55 by chanwjeo          #+#    #+#              #
#    Updated: 2022/08/08 11:14:19 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= ./libft
LIBFT_LIB	= libft.a

SRCS					= ft_printf.c print_str.c print_num.c print_hex_num.c

# BNS_SRCS				= ft_printf_bonus.c \
# 					  ft_printf_util_bonus.c \
# 					  ft_printf_c%_bonus.c \
# 					  ft_printf_diu_bonus.c \
# 					  ft_printf_diu_util_bonus.c \
# 					  ft_printf_xX_bonus.c \
# 					  ft_printf_xX_util_bonus.c \
# 					  ft_printf_s_bonus.c

BNS_SRCS 				= ft_printf_bonus.c ft_printf_utils_bonus.c \
							print_hex_num_bonus.c print_num_bonus.c print_num_precision_bonus.c \
							print_num_zero_bonus.c print_num_precision_2_bonus.c print_pointer_bonus.c \
							print_percent_bonus.c print_str_bonus.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all	:	$(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o			: %.c
	cc $(FLAGS) -c $^ -I./ -o $@

bonus :
	make WITH_BONUS=1 all

clean	:
		rm -f $(OBJS) $(BNS_OBJS)
		make clean -C $(LIBFT)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re	:	fclean all

.PHONY	:	all clean fclean re bonus


# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# SRCS = ft_printf.c print_str.c print_num.c print_hex_num.c
# BONUS = ft_printf_bonus.c ft_printf_utils_bonus.c \
# 		print_hex_num_bonus.c print_num_bonus.c print_num_precision_bonus.c \
# 		print_num_zero_bonus.c print_num_precision_2_bonus.c print_pointer_bonus.c \
# 		print_percent_bonus.c print_str_bonus.c

# OBJS = $(SRCS:.c=.o)
# OBJS_BONUS	= $(BONUS:c=o)

# ifdef BONUSFLAG
# 	ALLOBJ 	= $(OBJS) $(OBJS_BONUS)
# else
# 	ALLOBJ 	= $(OBJS)
# endif

# NAME = libftprintf.a
# LIBFTDIR	= ./libft
# LIBFTFILE	= libft.a

# AR = ar
# ARFLAGS = rc

# RM= rm -rf

# %.o : %c
# 	$(CC) $(CFLAGS) -c $< -I.

# $(NAME) : $(ALLOBJ)
# 	make -C $(LIBFTDIR)
# 	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
# 	$(AR) $(ARFLAGS) $@ $(ALLOBJ)

# all : $(NAME)

# bonus :
# 	make BONUSFLAG=1

# clean :
# 	make -C libft clean
# 	$(RM) $(OBJS) $(OBJS_BONUS)

# fclean : clean
# 	make -C libft fclean
# 	$(RM) $(NAME)

# re :
# 	make fclean
# 	make all

# .PHONY: all clean fclean re