# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 12:33:59 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/01 10:59:34 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cub3d_utils.c\
			cub3d_utils2.c\
			cub3d_utils3.c\
			get_next_line.c\
			init.c\
			main.c\
			map_parsing.c\
			map_parsing2.c\
			parsing.c\
			parsing2.c
			
OBJS	=	${SRCS:.c=.o}
BOBJS	=	${BSRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	cub3D

all		:	$(NAME)

$(NAME)	:	${OBJS}
	$(CC) $(CFLAGS) -o $@ $^

%.o		:	%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean	:
	rm -f ${OBJS} ${BOBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
