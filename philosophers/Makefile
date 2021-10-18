# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:57:24 by lmarzano          #+#    #+#              #
#    Updated: 2021/10/18 21:26:30 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	ARGS

NAME		=	philo

INCLUDE		=	./include/

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g -I $(INCLUDE) -pthread

RM		=	rm -rf

#	FILES

SRCS	=	srcs/actions.c \
			srcs/ft_lib.c \
			srcs/ft_lib2.c \
			srcs/ft_utils.c \
			srcs/main.c \
			srcs/parsing.c \
			srcs/thread_utils.c \
			srcs/thread.c
			
OBJS	=	$(SRCS:.c=.o)

#	RULES

all			:	philo score

$(NAME)		:	$(OBJS) $(INCLUDE)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				@$(RM) $(OBJS)

fclean		:	clean
				@$(RM) $(NAME)

philo		:	$(NAME)

re			:	fclean philo score

score		:
				@echo "------------------[PHILOSOPHERS]------------------"
				@echo "|               powered by lmarzano              |"
				@echo "----------------------[READY]---------------------"

joke		: 
				@echo "--------------------[PHILOSOPHERS]---------------------"
				@echo "| I am a machine, I don't have sense of humor. Sorry. |"
				@echo "-------------------------------------------------------"

.PHONY		:	philo clean fclean re score joke
