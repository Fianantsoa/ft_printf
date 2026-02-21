NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putunbr_fd.c ft_ltoh.c ft_strupcase.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	make -C libft

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
	make -C libft re

.PHONY : all clean fclean re