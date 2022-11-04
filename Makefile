# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 16:53:26 by gscarama          #+#    #+#              #
#    Updated: 2022/11/04 12:55:54 by gscarama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= main.c \
		utils.c \
		check_and_init.c \

CFLAGS	= -Wall -Wextra -Werror
GCC	= gcc
RM	= rm -rf

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	$(GCC) $(CFLAGS) ${OBJS} -o $(NAME)

all:	$(NAME)

norm:	norminette

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	.o all norm clean fclean re
