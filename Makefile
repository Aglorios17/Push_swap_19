# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglorios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by aglorios          #+#    #+#              #
#    Updated: 2021/03/09 13:38:54 by aglorios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECHECKER		= checker
NAMESWAP		= push_swap
LIBFT_PATH		= ./libft
SRCS 			= ./checker_prog/main/checker.c \

SRCS2 			= ./push_swap_prog/main/push_swap.c \

OBJS			= ${SRCS:.c=.o}
OBJS2			= ${SRCS2:.c=.o}
LIBFT			= libft
CC				= gcc -Wall -Wextra -Werror -g  #-fsanitize=address
RM				= rm -f

LIBFLAGS		= -I ./libft -L ./libft -L . ./libft/*.c
CHECKER_FLAGS	= -I ./checker_prog/include/ 
PUSH_SWAP_FLAGS	= -I ./push_swap_prog/include/ -L

all:			libft_all ${NAMECHECKER} #${NAMESWAP}
$(NAMECHECKER):	${OBJS} 
				$(CC) $(LIBFLAGS) libft/libft.a $(CHECKER_FLAGS) $(OBJS) -o $@ 
#$(NAMESWAP):	${OBJS2} 
#				$(CC) $(LIBFLAGS) libft/libft.a $(PUSH_SWAP_FLAGS) $(OBJS2) -o $@ 

clean:			libft_clean
				${RM} ${OBJS}
#				${RM} ${OBJS2}

fclean:			libft_fclean clean
				${RM} ${NAMECHECKER}
#				${RM} ${NAMESWAP}

re:				fclean all

libft_all:
	make -C $(LIBFT_PATH) all

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) libft/libft.a

.PHONY: all fclean clean re
