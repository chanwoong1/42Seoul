CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC = srcs
SRCS = $(SRC)/%.c
OBJS = $(SRCS:.c=.o)
HEADER = includes

all = $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS)
	ar -rcs $@ $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re
