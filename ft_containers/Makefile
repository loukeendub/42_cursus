# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 14:26:41 by lmarzano          #+#    #+#              #
#    Updated: 2022/06/03 16:59:24 by lmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Name:
NAME		=	ft_containers

#	Compiler:
CC			=	clang++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
CFLAG = 		-c
OFLAG =			-o
IFLAG =			-I

#Make:
MAKE = 			make -s -C
MAKE_CLEAN = 	make clean -s -C
MAKE_FCLEAN = 	make fclean -s -C

#Unzip:
UNZIP =			unzip -X -o -q

#Shell:
MKDIR =			mkdir -p
CP =			cp
RM =			rm -rf

#Directories:
SOURCES_DIR =	./src
OBJECTS_DIR =	./objs
HEADERS_DIR =	./hpp

#Files:
FILES =			main.cpp

#Srcs:
SRCS =			$(foreach FILE, $(FILES), $(shell find $(SOURCES_DIR) -name $(FILE)))

#Objs:
OBJS =			$(patsubst $(SOURCES_DIR)/%, $(OBJECTS_DIR)/%, $(SRCS:.cpp=.o))

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(HEADERS_DIR) $(CFLAG) $(OFLAG) $@ $<


#	RULES

all			:	joke run score

$(NAME)		:	$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) $(OFLAG) $(NAME)

re			:	fclean all

clean		:
			@$(RM) $(OBJS) $(OBJECTS_DIR)

fclean		:	clean
				@$(RM) $(NAME)

run			:	$(NAME)


score		:
				@echo "      -----------------[ ft_containers ]-----------------"
				@echo "      |               powered by lmarzano               |"
				@echo "      -----------------------[READY]---------------------"

joke		:
				@echo "      -----------------[ ft_containers ]-----------------"
				@echo ""
				@echo "       What do you call a container that's slightly open?"
				@echo ""
				@echo "                              Ajar."
				@echo "\n"
.PHONY		:	run clean fclean re score joke