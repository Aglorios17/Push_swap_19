# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 15:45:31 by aglorios          #+#    #+#              #
#    Updated: 2021/06/12 13:23:27 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	srcs/checker.c \
			srcs/checker_algo.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/norme_file.c \
			../main/utils.c \
			../main/arg_check.c \
			../src/operations/swap.c \
			../src/utils.c \
			../src/operations/rotate.c \
			../src/operations/push.c \
			../src/utils2.c \

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= checker

CC		= gcc -g #-fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. -I../libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C ../libft
		${CC} -o ${NAME} ${OBJS} -L../libft -lft

all: 		${NAME}

clean:
			make -C ../libft clean
			${RM} ${OBJS}

fclean:		clean
			make -C ../libft fclean
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all
