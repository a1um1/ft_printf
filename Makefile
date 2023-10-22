SRC		=	format/ft_char.c format/ft_number.c format/ft_percent.c \
			format/ft_string.c ft_printf.c libft/str/ft_strlen.c
SRCS	=	${addprefix ${SRC_DIR}, ${SRC}}
OBJ		=	${SRCS:.c=.o}
NAME	=	libftprintf.a

all: ${NAME}

.c.o: 		ft_printf.h
	cc -Wall -Werror -Wextra -I . -c $< -o $@

libft/libft.a:
	make -C libft

${NAME}: 	libft/libft.a ${OBJ}
	cp	libft/libft.a $(NAME)
	ar rcs ${NAME} ${OBJ}

debug: 		all
	cc -I . -L . -l ftprintf test/basic.c  -o ft_printf

clean:
	rm -f ${OBJ}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

norm:
	norminette $(SRC) . ./libft | grep -v Norme -B1 || true

.PHONY: all clean fclean re debug norm
