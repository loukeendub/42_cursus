# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 11:08:25 by lmarzano          #+#    #+#              #
#    Updated: 2021/03/01 14:37:24 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			int_manager.c \
			order_manager.c \
			parse_struct.c \
			print_order_cs.c \
			print_order_d.c \
			print_order_minus_d.c \
			print_order_p.c \
			print_order_u.c \
			print_order_x.c \
			types.c \
			utils.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

AR		=	ar -rcs

%.o		: %.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
			${AR} ${NAME} ${OBJS}

all		:	${NAME}

bonus	: 	re

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus
