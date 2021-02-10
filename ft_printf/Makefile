# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 11:08:25 by lmarzano          #+#    #+#              #
#    Updated: 2021/02/10 12:05:40 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c tools.c checker.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
AR		=	ar -rcs

%.o		: %.c
			${CC} ${CFLAGS} -c $^ -o $@

${NAME}	:	${OBJS}
			${AR} ${NAME} ${OBJS}

all		:	${NAME}

test	:	all
			${CC} ${CFLAGS} ${NAME} main.c -o test
			./test
			rm test

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
