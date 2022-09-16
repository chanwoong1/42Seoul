# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/09/16 23:28:45 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME		=	philosophers
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

# HEADER
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# FILES
MPATH_SRCS	=	main.c map_checker.c utils.c mlx_utils.c init.c \
				move_w.c move_a.c move_s.c move_d.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			all

clean:
				@$(RM) $(OBJ_M)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m
