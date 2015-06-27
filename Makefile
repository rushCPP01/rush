#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 17:14:27 by igomez            #+#    #+#              #
#    Updated: 2015/06/27 21:32:03 by avallete         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= ft_gkrellm

SRC_D	= srcs
INC_D	= includes

SRC 	=	$(shell find $(SRC_D) -type f | grep "\.cpp")
OBJ 	=	$(SRC:.cpp=.o)
LIB 	=	-lncurses

CC		= /usr/bin/clang++

RM		= /bin/rm -f

CFLAGS = -Wall -Wextra -Werror -g -I ./$(INC_D)/

$(NAME):	$(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) && \
		printf "                                                                   \r" && \
		printf "\033[0;32m\033[1m   %-28s\033[0m -->>\t\033[1m\033[31m[%s]\033[0;0m\n" \
		"Compiling..." "$@"

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

all:		$(NAME)

re:		fclean all

.PHONY:		re all clean fclean

.cpp.o:
	@$(CC) $(CFLAGS) -std=c++11 -o $@ -c $< \
	&& (printf "\r \033[0;0m%-30s\033[1;30m -->>\t\033[0;31m$@\033[0;0m" "$<" \
	&& printf "            \r") \
	|| (printf "\033[0;0m%-30s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
		&& exit 1)
