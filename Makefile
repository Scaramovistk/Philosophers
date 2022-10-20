# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 16:53:26 by gscarama          #+#    #+#              #
#    Updated: 2022/10/06 16:57:01 by gscarama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SOURCE	= main.c

CFLAGS	= -Wall -Wextra -Werror
GCC	= gcc
RM	= rm -rf
PATH_SRC	= srcs
PATH_OBJ	= objs

SRCS	= $(addprefix $(PATH_SRC)/,$(SOURCE))
OBJS	= $(addprefix $(PATH_OBJ)/,$(SOURCE:.c=.o))

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c
			${GCC} ${CFLAGS} -c $< -o ${<:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o}

$(NAME):	${OBJS}
	make -C ./ft_printf
	cp ft_printf/libftprintf.a .
	mv libftprintf.a ${NAME}
	$(GCC) $(CFLAGS) ${OBJS} ${NAME} -o $(NAME)

all:	$(NAME)

norm:	norminette

clean:
	${RM} ${OBJS}
	make -C ./ft_printf clean

fclean:	clean
	${RM} ${NAME}
	make -C ./ft_printf fclean

re:	fclean all

.PHONY:	.o all norm clean fclean re
