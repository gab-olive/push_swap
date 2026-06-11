NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -c

INCDIR	= .

SRCS	=	ft_strlen.c \
			ft_ischar.c \
			ft_memcpy_memmove.c \
			ft_memset_bzero.c \
			ft_toupper_tolower.c \
			ft_strchr_strrchr_memchr.c \
			ft_strlcpy_strlcat.c \
			ft_memcmp_strncmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_substr.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstclear.c \
			ft_lstlast.c \
			ft_printf.c \
			ft_printf/char_handler.c \
			ft_printf/dec_handler.c \
			ft_printf/hex_handler.c \
			ft_printf/ptr_handler.c \
			ft_printf/str_handler.c \
			ft_printf/uint_handler.c \
			ft_printf/ft_putchar.c \
			ft_printf/ft_putnbr_base.c \
			ft_printf/ft_putstr.c \
			ft_printf/ft_putuint_base.c \
			ft_printf/ft_putunbr_base.c
OBJS	= ${SRCS:.c=.o}

RM		= rm -f

$(info $(OBJS) $(SRCS))

all:		${NAME}

bonus: ${NAME}

%.o: %.c
			${CC} ${CFLAGS} $< -o $@ -I ${INCDIR}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all
