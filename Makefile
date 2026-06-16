NAME			= push_swap

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3
LIBFT			= libft/libft.a
INCLUDES		= -Ilibft -Iincludes
LIBS			= -Llibft -lft

SRCS			= $(wildcard util/*.c) $(wildcard util/*/*.c) push_swap.c
OBJS			= ${SRCS:.c=.o}

.PHONY: 		all clean fclean re

all: 			$(NAME)

$(NAME):		$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

%.o:			%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean:			clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re:				fclean all
