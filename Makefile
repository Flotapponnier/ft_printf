CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes
RM = rm -rf
NAME = libftprintf.a
TEST_PROG = test_printf

SRCS = srcs/ft_printf.c srcs/ft_format.c srcs/ft_format2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(TEST_PROG)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_PROG) ${SRC} $(NAME) -Llibft -lft
	./$(TEST_PROG)

.PHONY: all clean fclean re test

.SILENT:

