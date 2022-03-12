CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c

SRCS=./*.c ./libft/ft*.c

OBJECTS=*.o
LIB_PATH = ./libft
INCLUDES=./ft_printf.h

all: 	
	@make re -C $(LIB_PATH)
	@$(CC) -g3 $(CFLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJECTS) $(LIB_PATH)/*.o

$(NAME):
	@make re -C $(LIB_PATH)
	@$(CC) -g3 $(CFLAGS) $(SRCS) -I$(INCLUDES)
	@ar rc $(NAME) $(OBJECTS) $(LIB_PATH)/*.o
	@ranlib $(NAME)
	@make fclean -C $(LIB_PATH)
	
clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)


fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all

.PHONY:	all clean fclean re

norm:
	norminette
