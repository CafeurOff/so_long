NAME = get_next_line.a

HEADER = get_next_line.h
SRCS = get_next_line_utils.c get_next_line.c
OBJS = $(SRCS:.c=.o)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) -D BUFFER_SIZE=1000
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all