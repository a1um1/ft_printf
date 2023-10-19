SRC = format/ft_char.c format/ft_number.c format/ft_percent.c format/ft_string.c ft_printf.c
SRCS = ${addprefix ${SRC_DIR}, ${SRC}}
OBJ = ${SRCS:.c=.o}
NAME = ft_printf

all: ${NAME}

.c.o: ft_printf.h
	cc -lft -Llibft -I . -c $< -o $@

libft:
	(cd libft && make all && make clean)

${NAME}: libft ${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re SRC
