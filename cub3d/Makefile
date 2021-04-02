# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 12:33:59 by lmarzano          #+#    #+#              #
#    Updated: 2021/04/02 14:39:11 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	cub3d.c\
					core.c\
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
#BSRCS			=
			
#BOBJS			=	$(BSRCS:.c=.o)
OBJS			=	$(CUB_DIRSRCS:.c=.o)
DIR				= engine/
RAN				= ranlib
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
CMLXFLAGS		= -lmlx -framework OpenGL -framework AppKit
CUB_DIRSRCS		= $(addprefix $(DIR), $(SRCS))
#CUB_DIRBSRCS	= $(addprefix $(DIR), $(BSRCS))
NAME			=	cub3D
RM				= rm -f

all		:	$(NAME)

$(NAME)	:	${OBJS}
	$(CC) $(CFLAGS) ${CMLXFLAGS} ./engine/$(NAME) engine/main.c libmlx.dylib -o $@ $^
	@$(RAN) $(NAME)
	@mv $(NAME) engine
	@make -C mlx
	@cp mlx/libmlx.dylib .

%.o		:	%.c
	$(CC) $(CFLAGS) ${CMLXFLAGS} -c -o $@ $^

clean	:
	rm -f ${OBJS} ${BOBJS}
	@make clean -C mlx

fclean	:	clean
	$(RM) ${NAME}
	@$(RM) ./engine/$(NAME)
	@$(RM) libmlx.dylib
	@$(RM) cub3d


re		:	fclean all

.PHONY	:	all clean fclean re
