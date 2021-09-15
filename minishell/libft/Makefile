# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 17:59:12 by lmarzano          #+#    #+#              #
#    Updated: 2021/09/15 17:59:14 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	  ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	  ft_substr.c ft_tolower.c ft_toupper.c ft_lstmap.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c \
	  ft_lstdelone.c ft_lstlast.c ft_lstsize.c ft_lstnew.c ft_lstadd_front.c ft_lstfirst.c

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Wextra -Werror

%.o :		%.c
			gcc -c -g -I./libft $(CFLAGS) $< -o $@

$(NAME): 	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

all: 		$(NAME)

clean:
			@rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)

re: 		fclean all
