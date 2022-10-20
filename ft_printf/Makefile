NAME	= libftprintf.a

SRCS	= ft_printf.c \
			ft_printhex.c \
			ft_printnbr.c \
			ft_printstr.c \
			ft_printunnbr.c \
			ft_printvoid.c \

OBJ	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror
GCC	= gcc
RM	= rm -f
LIB	= ar rcs
LIBPATH	= .

%.o:	%.c
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(LIBPATH)

$(NAME):	${OBJ}
	make -C ./libft
	cp libft/libft.a .
	mv libft.a ${NAME}
	${LIB} ${NAME} ${OBJ}

all:	$(NAME)

norm:	norminette

clean:
	${RM} ${OBJ} ${OBJ_b}
	make -C ./libft clean

fclean:	clean
	${RM} ${NAME}
	make -C ./libft fclean

re:	fclean all

.PHONY:	.o all norm clean fclean re