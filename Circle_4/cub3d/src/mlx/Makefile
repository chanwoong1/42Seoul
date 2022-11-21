


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@echo "$(MAGENTA)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(MAGENTA)║        Minilibx compile finished.        ║$(DEF_COLOR)"
	@echo "$(MAGENTA)╚══════════════════════════════════════════╝$(DEF_COLOR)"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "$(MAGENTA)Compiling... \t$< $(DEF_COLOR)"

%.o: %.swift
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
	@echo "$(MAGENTA)Compiling... \t$< $(DEF_COLOR)"

%.swiftmodule: %.swift
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)
	@echo "$(MAGENTA)Compiling... \t$< $(DEF_COLOR)"

clean:
	@rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
	@echo "$(MAGENTA)MLX archive files has been deleted.$(DEF_COLOR)"

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