# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 09:17:58 by lmarzano          #+#    #+#              #
#    Updated: 2021/01/20 12:54:34 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
AR		=	ar -rcs

.c.o	:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME)	:	${OBJS}
			${AR} $(NAME) $(OBJS)
all		:	$(NAME)
clean	:
			rm -f ${OBJS}
fclean	:	clean
			rm -f ${NAME}
re		:	fclean all
.PHONY	:	all clean fclean re
