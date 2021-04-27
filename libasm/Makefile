# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 17:43:38 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/27 17:59:29 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRCS	=

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

AR		=	ar -rcs

# bonus

BSRCS	=

BOBJ	=	$(BSRCS:.c=.o)

# rules

%.o		:	%.c
			${CC} ${CFLAGS} -c $< -o $@

$(NAME)	:	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all		:	$(NAME)

clean	:
			rm -f $(OBJ) $(BOBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

bonus	:	$(OBJ) $(BOBJ)
			$(AR) $(NAME) $(OBJ) $(BOBJ)

.PHONY	:	all clean fclean re bonus
