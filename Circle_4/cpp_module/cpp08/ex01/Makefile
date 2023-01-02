# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 14:31:20 by chanwjeo          #+#    #+#              #
#    Updated: 2023/01/02 14:52:59 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= a.out

# CXXFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98

# NOTE : Add Source directory here
# ------------------------------------------------------ #
# SRC_DIR			= src

# NOTE : Add Source files here
# ------------------------------------------------------ #
# MAIN_SRC		= main

# NOTE : Add to SRC here
# ------------------------------------------------------ #
# SRC = $(addsuffix .c, $(addprefix $(MAIN_DIR), $(MAIN_SRC))) 

SRC = main.cpp Span.cpp

# ------------------------------------------------------ #

OBJ = $(SRC:cpp=o)

all: $(NAME)

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
ORANGE = \033[38;5;208m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
CUSTOM = \033[38;5;135m

#-----------------------------------------------------------------------
#    Mac compile option                                                |
#-----------------------------------------------------------------------
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(GREEN)║      cpp_08 ex01 compile finished.       ║$(DEF_COLOR)"
	@echo "$(GREEN)╚══════════════════════════════════════════╝$(DEF_COLOR)"

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@
	@echo "$(GREEN)Compiling... \t$< $(DEF_COLOR)"
# #-----------------------------------------------------------------------

clean:
	@rm -f $(OBJ)
	@echo "$(CUSTOM)ex01 obj files has been deleted.$(DEF_COLOR)"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "$(CUSTOM)ex01 archive files has been deleted.$(DEF_COLOR)"

re: fclean all
	@echo "$(CUSTOM)Cleaned and rebuilt ex01.$(DEF_COLOR)"

.PHONY: all clean fclean re
