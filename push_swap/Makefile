# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:40:50 by lmarzano          #+#    #+#              #
#    Updated: 2021/09/21 12:27:00 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	ARGS

PUSH		=	push_swap

LIB_PATH 	=	./libft

INCLUDE		=	-I include

LIB			=	$(LIB_PATH)/libft.a

LIB_LINK    =  -L $(LIB_PATH) -lft

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

AR		=	ar -rcs

RM		=	rm -rf

#	FILES

PSSRCS	=	srcs/main.c \
			srcs/ft_utils.c \
			srcs/ft_utils2.c \
			srcs/ft_sort.c \
			srcs/ft_save_moves.c \
			srcs/ft_rotations.c \
			srcs/ft_push.c \
			srcs/ft_pscheckval.c \
			srcs/ft_pscheckarg.c \
			srcs/ft_moves.c \
			srcs/ft_movecount.c \
			srcs/ft_head_manager.c \
			srcs/ft_flags.c \
			srcs/ft_flag_utils.c \
			srcs/ft_find.c \
			srcs/ft_exec2.c \
			srcs/ft_exec.c \
			srcs/ft_quicksort.c \
			srcs/ft_commands2.c \
			srcs/ft_commands.c
			
PSOBJS	=	$(PSSRCS:.c=.o)

#	RULES

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< $(INCLUDE) -o $@

$(LIB)		:
				make -C $(LIB_PATH)

lib		:	$(LIB)

$(PUSH)		:	$(PSOBJS)
				$(CC) $(CFLAGS) -o $(PUSH) $(PSOBJS) $(LIB) $(INCLUDE)

clean		:
				$(RM) $(PSOBJS) $(LIB_PATH)/*.o
				make -C libft/ clean

fclean		:	clean
				$(RM) $(PUSH)
				@make fclean -C libft/

ps			:	$(LIB) $(PUSH)

re			:	fclean ps joke

joke		: 
				@echo --------------------[PUSH  SWAP]---------------------
				@echo powered by lmarzano. visit www.push_swap_must_die.com
				@echo -----------------------[READY]-----------------------

.PHONY		:	ps clean fclean re joke
