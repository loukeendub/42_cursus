# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 12:33:59 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/07 15:26:07 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Imlx -Iinc -g
FFLAGS		=	-framework OpenGL -framework AppKit
RM			=	rm -f

SRCDIR		=	src/

FILES		=	cub3d.c\
				core.c\
				cub3d-2.c\
				cub3d-3.c\
				cub3d-4.c\
				cub3d_utils.c\
				cub3d_utils2.c\
				cub3d_utils3.c\
				get_next_line.c\
				init.c\
				main.c\
				map_parsing.c\
				map_parsing2.c\
				parsing.c\
				parsing2.c
SRC			=	$(addprefix $(SRCDIR), $(FILES))
OBJ			=	$(SRC:.c=.o)

MLX			=	libmlx.dylib

all		:	$(NAME)

$(NAME)	:	$(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(FFLAGS) $^ -o $@

$(MLX)	:
	@make -C mlx
	@cp mlx/$(MLX) . 

$(SRCDIR)/%.o	:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean	:
	rm -f $(OBJ)
	@make clean -C mlx

fclean	:	clean
	@$(RM) $(MLX)
	@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

test	:	all
	./cub3D map.cub