# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/09/18 22:58:37 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
MLX			=	-L./mlx -lmlx -framework OpenGL -framework AppKit

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

BPATH_SRCS	=	main_bonus.c map_checker_bonus.c utils_bonus.c valid_utils_bonus.c mlx_utils_bonus.c init_bonus.c \
				move_w_bonus.c move_a_bonus.c move_s_bonus.c move_d_bonus.c move_enemy_bonus.c \
				put_char_sprite_img_bonus.c put_enm_sprite_img_bonus.c put_obj_img_bonus.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c ft_memset.c \
				ft_strlen.c ft_strchr.c ft_putstr_fd.c ft_putnbr_fd.c ft_itoa.c
FUNC_DIR	=	libft/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_M)
				@$(CC) $(OBJ_F) $(OBJ_M) $(MLX) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			fclean $(OBJ_F) $(OBJ_B)
				@$(CC) $(OBJ_F) $(OBJ_B) $(MLX) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
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
