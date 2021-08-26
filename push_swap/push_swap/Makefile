# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:40:50 by lmarzano          #+#    #+#              #
#    Updated: 2021/06/17 12:23:41 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	ARGS

PUSH		=	push_swap

CHECK 		=	checker

LIB_PATH 	=	libft

INCLUDE		=	push_swap.h

LIB			=	$(LIB_PATH)/libft.a

LIB_LINK    =  -L $(LIB_PATH) -lft

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

AR		=	ar -rcs

RM		=	rm -rf

#	FILES

CHSRCS	=	CHR/main.c \
			CHR/ft_checker.c \
			CHR/ft_commands.c \
			CHR/ft_checkval.c \
			CHR/ft_moves.c

CHOBJS	=	$(CHSRCS:.c=.o)

PSSRCS	=	P_S/main.c \
			P_S/ft_pscheckarg.c \
			P_S/ft_pscheckval.c \
			P_S/ft_pscommands.c \
			P_S/ft_psmoves.c \
			P_S/ft_utils.c \
			P_S/push_swap.c

PSOBJS	=	$(PSSRCS:.c=.o)

#	RULES

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

all			:	$(LIB) $(CHECK) $(PUSH)

$(LIB)		:
				make -C $(LIB_PATH)

$(CHECK)	:	$(CHOBJS)
				$(CC) $(CFLAGS) -o $(CHECK) $(CHOBJS) $(LIB) -I $(INCLUDE)


$(PUSH)		:	$(PSOBJS)
				$(CC) $(CFLAGS) -o $(PUSH) $(PSOBJS) $(LIB) -I $(INCLUDE)

clean		:
				$(RM) $(CHOBJS) $(PSOBJS) $(LIB_PATH)/*.o
				make -C libft/ clean

fclean		:	clean
				$(RM) $(CHECK)
				$(RM) $(PUSH)
				make -C libft/ fclean

re			:	fclean all

.PHONY		:	all clean fclean re
