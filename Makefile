CC			= gcc

NAME		= pacman

SRCS		= pacman.c \
					mapa.c \
					ui.c

OBJS		= $(SRCS:.c=.o)

CFLAGS	= -std=c99 -Wall -Wextra -Werror

RM			= rm -f

all:		$(NAME)

$(NAME): $(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
