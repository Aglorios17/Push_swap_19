# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglorios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 15:45:31 by aglorios          #+#    #+#              #
#    Updated: 2021/06/03 13:09:34 by aglorios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	main/checker.c \
			main/checker_algo.c \
			utils/utils.c \
			utils/utils2.c \
			operations/push.c \
			operations/rotate.c \
			operations/swap.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/norme_file.c

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= checker

CC		= gcc -g -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. -I./libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		${CC} -o ${NAME} ${OBJS} -L./libft -lft

all: 		${NAME}

clean:
			make -C libft clean
			${RM} ${OBJS}

fclean:		clean
			make -C libft fclean
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all
