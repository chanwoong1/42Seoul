# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:00:00 by chanwjeo          #+#    #+#              #
#    Updated: 2022/11/29 17:56:36 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= replace
TEST_NAME = tester

# CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS			= -Wall -Wextra -Werror -std=c++98

# NOTE : Add Source directory here
# ------------------------------------------------------ #
# SRC_DIR			= src
TEST_DIR   = ex04_tester

# NOTE : Add Source files here
# ------------------------------------------------------ #
# MAIN_SRC		= main

# NOTE : Add to SRC here
# ------------------------------------------------------ #
# SRC = $(addsuffix .c, $(addprefix $(MAIN_DIR), $(MAIN_SRC))) 

SRC = main.cpp ReadFile.cpp
TEST_SRC  = ./$(TEST_DIR)/tester.cpp \
            ./$(TEST_DIR)/TestClass.cpp \
            ReadFile.cpp

# ------------------------------------------------------ #

OBJ = $(SRC:cpp=o)
TEST_OBJ = $(TEST_SRC:cpp=o)

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
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(GREEN)║      cpp_01 ex04 compile finished.       ║$(DEF_COLOR)"
	@echo "$(GREEN)╚══════════════════════════════════════════╝$(DEF_COLOR)"

%.o: %.cpp
	@${CXX} ${CFLAGS} -c $< -o $@
	@echo "$(GREEN)Compiling... \t$< $(DEF_COLOR)"
# #-----------------------------------------------------------------------

tester: $(TEST_OBJ)
	@$(CXX) $(CFLAGS) $(TEST_OBJ) -o $(TEST_NAME)
	@echo "$(GREEN)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(GREEN)║   cpp_01 ex04 tester compile finished.   ║$(DEF_COLOR)"
	@echo "$(GREEN)╚══════════════════════════════════════════╝$(DEF_COLOR)"

clean:
	@rm -f $(OBJ) $(TEST_OBJ)
	@echo "$(CUSTOM)ex04 obj files has been deleted.$(DEF_COLOR)"

fclean:
	@rm -f $(OBJ) $(TEST_OBJ)
	@rm -f $(NAME) $(TEST_NAME)
	@echo "$(CUSTOM)ex04 archive files has been deleted.$(DEF_COLOR)"

re: fclean all
	@echo "$(CUSTOM)Cleaned and rebuilt ex04.$(DEF_COLOR)"

.PHONY: all clean fclean re
