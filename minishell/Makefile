# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 18:02:25 by lmarzano          #+#    #+#              #
#    Updated: 2021/09/15 18:02:27 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

NAME_BONUS = minishell_bonus

SRCS		=	\
				command/all_com.c \
				command/cd.c \
				command/echo.c \
				command/env.c \
				command/exit.c \
				command/export.c \
				command/pwd.c \
				command/unset.c \
				command/utils.c \
				file_manager/file.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				parse/parse_dollar.c \
				parse/parse_check.c \
				parse/parse_create.c \
				parse/parse_manager.c \
				parse/parse_utils.c \
				parse/parse.c \
				pipe/exec_pipe.c \
				pipe/create_pipe.c \
				read/prompt.c \
				read/read.c \
				read/history.c \
				srcs/create_path.c \
				srcs/error.c \
				srcs/main.c \
				utils/data_utils.c \
				utils/env_utils.c \
				utils/file_utils.c \
				utils/flag_utils.c \
				utils/lst_utils.c \
				utils/mtr_utils.c \
				utils/signal_utils.c \
				utils/utils.c \
				utils/utils_2.c \
				utils/utils_3.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

%.o :		%.c
			gcc -c -g -I./include -I./libft -I./gnl $< -o $@

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			gcc $(CFLAGS) $(OBJS) libft.a -o $(NAME) -lreadline

all:		$(NAME)

clean:		
			rm -f $(OBJS)
			make -C libft clean

fclean:		clean
			rm -f $(NAME) libft.a

re:			fclean all

.PHONY:		all clean fclean re
