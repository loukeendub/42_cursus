# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:40:50 by lmarzano          #+#    #+#              #
#    Updated: 2021/05/13 16:52:48 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	ARGS

NAME	=	push_swap.a

SRCS	=	# all names of files .c go here!!!!

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

AR		=	ar -rcs

#	RULES

%.o		:	%.c

$(NAME)	:	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all		:	$(NAME)

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re