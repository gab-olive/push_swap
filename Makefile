NAME			= push_swap

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3
LIBFT			= libft/libft.a
INCLUDES		= -Ilibft -Iincludes
LIBS			= -Llibft -lft

SRCS			= push_swap.c \
			  util/args.c \
			  util/bench.c \
			  util/disorder.c \
			  util/is_number.c \
			  util/math.c \
			  util/stats_store.c \
			  util/algorithms/chunk.c \
			  util/algorithms/minsort.c \
			  util/algorithms/radix.c \
			  util/ft_printf_fd/char_handler_fd.c \
			  util/ft_printf_fd/dec_handler_fd.c \
			  util/ft_printf_fd/ft_printf_fd.c \
			  util/ft_printf_fd/ft_putchar_fd_count.c \
			  util/ft_printf_fd/ft_putnbr_base_fd_count.c \
			  util/ft_printf_fd/ft_putstr_fd_count.c \
			  util/ft_printf_fd/ft_putuint_base_fd_count.c \
			  util/ft_printf_fd/ft_putunbr_base_fd_count.c \
			  util/ft_printf_fd/hex_handler_fd.c \
			  util/ft_printf_fd/ptr_handler_fd.c \
			  util/ft_printf_fd/str_handler_fd.c \
			  util/ft_printf_fd/uint_handler_fd.c \
			  util/ops/push.c \
			  util/ops/reverse_rotate.c \
			  util/ops/rotate.c \
			  util/ops/swap.c \
			  util/stack/from_args.c \
			  util/stack/is_sorted.c \
			  util/stack/stack.c
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
