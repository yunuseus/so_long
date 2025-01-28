NAME := so_long

CC := cc


SOURCE := so_long.c get_next_line.c get_next_line_utils.c puts.c map_check.c moving.c end.c
LIBRARY := -Lminilibx -lmlx -lX11 -lXext -lm
MINILIBX := minilibx-linux/
PRINTF := printf/libftprintf.a

all:
	make -C $(MINILIBX)
	make -C printf
	$(CC) $(CFLAGS) $(SOURCE)  $(LIBRARY) $(PRINTF) -o $(NAME) -g

clean:
		make clean -C printf
		make clean -C $(MINILIBX)

fclean: clean
		make clean -C $(MINILIBX)
		make fclean -C printf
		rm -rf $(NAME)

re: fclean all