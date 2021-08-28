# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loukeen <loukeen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 11:17:02 by lmarzano          #+#    #+#              #
#    Updated: 2021/07/28 17:09:31 by loukeen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	ARGS

PIPEX		=	pipex

LIB_PATH	=	libft

INCLUDE		=	inc/pipex.h

LIB			=	$(LIB_PATH)/libft.a

LIB_LINK	=	-L $(LIB_PATH) -lft

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

AR			=	ar -rcs

RM			=	rm -rf

#	FILES

SRCS		=	srcs/parse.c \
				srcs/pipex.c \
				srcs/utils.c

OBJS		=	$(SRCS:.c=.o)

#	RULES

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

all			:	$(LIB) $(PIPEX)

$(LIB)		:
				make -C $(LIB_PATH)

$(PIPEX)	:	$(OBJS)
				$(CC) $(CFLAGS) -o $(PIPEX) $(OBJS) $(LIB) -I $(INCLUDE)

clean		:
				$(RM) $(OBJS) $(LIB_PATH)/.o
				make -C libft/ clean

fclean		:	clean
				$(RM) $(PIPEX)
				make -C libft/ fclean

re			:	fclean all

.PHONY		:	all clean fclean re
