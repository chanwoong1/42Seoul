# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/10/03 14:03:24 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

# HEADER
HEADER_SRCS	=	minishell.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

LFT_DIR = ./libft
LFT_FLAG = -L$(LFT_DIR) -lft -lreadline -I$(LFT_DIR)

# FILES
PROMPT		=	prompt
PARSE		=	parse
UTILS		=	utils
HEREDOC		=	heredoc
MPATH_SRCS	=	$(PROMPT)/prompt.c \
				$(UTILS)/util_free.c \
				$(UTILS)/util_print.c \
				$(PARSE)/init_parse.c \
				$(PARSE)/init_shell.c \
				$(PARSE)/history.c \
				$(PARSE)/fd.c \
				$(HEREDOC)/heredoc.c
MPATH_DIR	=	srcs/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

FUNC 		=	gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_M) $(OBJ_F)
				@make -s -C $(LFT_DIR)
				@$(CC) $(CFLAGS) $(LFT_FLAG) $(OBJ_M) $(OBJ_F) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			all

clean:
				@make -s -C $(LFT_DIR) clean
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@make -s -C $(LFT_DIR) fclean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m
