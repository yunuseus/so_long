NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c get_next_line.c get_next_line_utils.c puts.c \
       map_check.c moving.c end.c too_many_functions.c checks.c flood_fill.c map_file_check.c

OBJ = $(SRC:.c=.o)

LIBRARY = -Lminilibx-linux -lmlx -lX11 -lXext -lm
MINILIBX = minilibx-linux/
PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	make -C printf
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C printf
	make clean -C $(MINILIBX)
	rm -f $(OBJ)

fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C printf
	rm -f $(NAME)

re: fclean all