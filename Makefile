SRC		=	format/ft_char.c format/ft_number.c format/ft_percent.c \
			format/ft_string.c ft_printf.c libft/str/ft_strlen.c
SRCS	=	${addprefix ${SRC_DIR}, ${SRC}}
OBJ		=	${SRCS:.c=.o}
NAME	=	ft_printf.a

all: ${NAME}

.c.o: 		ft_printf.h
	cc -I . -L ./libft -l ft -c $< -o $@

libft/libft.a:
	make -C libft

${NAME}: 	libft/libft.a ${OBJ}
	ar -rcs	${NAME} ${OBJ}

debug: 		libft/libft.a ${OBJ}
	cc -I . ${OBJ} -o ft_printf

clean:
	rm -f ${OBJ}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

norm:
	norminette $(SRC) . ./libft | grep -v Norme -B1 || true

.PHONY: all clean fclean re debug norm
