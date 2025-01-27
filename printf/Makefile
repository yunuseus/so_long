NAME = libftprintf.a

SRCS = ft_printf.c ft_printall.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = rm -f
CC = cc

$(NAME):$(OBJS) 
		ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)



clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) 

re: fclean all