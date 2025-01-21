NAME := so_long

CC := gcc


SOURCE := so_long.c get_next_line.c get_next_line_utils.c ft_strlen.c map_check.c
LIBRARY := -Lminilibx -lmlx -lX11 -lXext -lm
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE)  $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all