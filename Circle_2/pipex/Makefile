# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/09/12 10:58:00 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM= rm -rf

# HEADER
HEADER_SRCS	=	pipex.h pipex_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# FILES
MPATH_SRCS	=	pipex.c childs.c error.c free.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	pipex_bonus.c error_bonus.c here_doc_bonus.c\
				files_bonus.c free_bonus.c child_bonus.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c
FUNC_DIR	=	libft/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				gnl/gnl_bonus.c gnl/gnl_utils_bonus.c
OBJ_F		=	$(FUNC:.c=.o)

OBJS = main_bonus.c utils_bonus.c parse_bonus.c heredoc_bonus.c gnl_bonus.c gnl_utils_bonus.c

OBJS_FILES	= $(OBJS:c=o)

LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS_FILES)
	@make all -C $(LIBFTDIR)/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_FILES) -L ./libft -lft

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


# #SETUP
# NAME		=	pipex
# CC			=	gcc
# FLAGS		=	-Wall -Wextra -Werror
# RM			=	rm -rf




# #COMMANDS
# %.o: %.c $(HEADER) Makefile
# 				@${CC} ${FLAGS} -c $< -o $@

# $(NAME):		$(OBJ_F) $(OBJ_M)
# 				@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
# 				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

# all:			$(NAME)

# bonus:			$(OBJ_F) $(OBJ_B)
# 				@$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME)
# 				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

# clean:
# 				@$(RM) $(OBJ_M)
# 				@$(RM) $(OBJ_F)
# 				@$(RM) $(OBJ_B)
# 				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

# fclean:			clean
# 				@$(RM) $(NAME)
# 				@echo -e "$(RED)all deleted!$(DEFAULT)"

# re:				fclean all

# .PHONY:		all clean fclean bonus re

# #COLORS
# RED = \033[1;31m
# GREEN = \033[1;32m
# YELLOW = \033[1;33m
# DEFAULT = \033[0m
