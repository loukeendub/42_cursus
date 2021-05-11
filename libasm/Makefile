# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 17:43:38 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/10 14:39:11 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRCS	=	ft_read.s ft_write.s ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s

OBJ		=	$(SRCS:.s=.o)

CC		=	nasm

CFLAGS	=	-fmacho64

AR		=	ar -rcs

# bonus

BSRCS	=

BOBJ	=	$(BSRCS:.s=.o)

# rules

%.o		:	%.s
			${CC} ${CFLAGS} -o $@ $<
 
$(NAME)	:	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all		:	$(NAME)

clean	:
			rm -f $(OBJ) $(BOBJ)

fclean	:	clean
			rm -rf ft_write.res
			rm -rf test
			rm -f $(NAME)

re		:	fclean all

test	:	all
			gcc -Wall -Wextra -Werror main.c functions.c libasm.a -o test


.PHONY	:	all clean fclean re bonus
