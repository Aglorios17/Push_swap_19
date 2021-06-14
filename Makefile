# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 12:39:59 by thgillai          #+#    #+#              #
#    Updated: 2021/06/12 13:17:58 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	main/main.c \
			main/utils.c \
			main/arg_check.c \
			src/operations/swap.c \
			src/utils.c \
			src/operations/rotate.c \
			src/operations/push.c \
			src/utils2.c \
			src/algo.c \
			src/algo_3nb.c \
			src/algo_5nb.c

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc -g #-fsanitize=address
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
			make -C checker_bonus clean
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			make -C libft fclean
			make -C checker_bonus fclean
			rm ./checker

re:		fclean all

 bonus:     	all
			make -C checker_bonus
			mv ./checker_bonus/checker .
		
c:		bonus clean

.PHONY:		clean fclean re all
