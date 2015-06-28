NAME	= ft_gkrellm

SRC_D	= srcs
INC_D	= includes
# LIBS =	-L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system\
# 		SFML/Frameworks/sfml-graphics.framework/sfml-graphics\
# 		SFML/Frameworks/sfml-window.framework/sfml-window\
# 		SFML/Frameworks/sfml-system.framework/sfml-system
# LIBS = -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

LDENV = DYLD_FRAMEWORK_PATH="$(shell pwd)/SFML/Frameworks"
# export DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks"

SRC 	=	$(shell find $(SRC_D) -type f | grep "\.cpp")
OBJ 	=	$(SRC:.cpp=.o)
LIB 	=	-framework sfml-graphics -framework sfml-window -framework sfml-system\
		-F SFML/Frameworks -lncurses

CC		= /usr/bin/clang++

RM		= /bin/rm -rf

CFLAGS = -Wall -Wextra -Werror -g -I ./$(INC_D)/ -I $(shell pwd)/SFML/include


all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) && \
		printf "                                                                   \r" && \
		printf "\033[0;32m\033[1m   %-28s\033[0m -->>\t\033[1m\033[31m[%s]\033[0;0m\n" \
		"Compiling..." "$@"

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

launch:
	@DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./ft_gkrellm -ng



rmsfml:
	$(RM) SFML
sfml: rmsfml
	curl -O "http://mirror0.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz" 
	mkdir SFML
	tar -xzf SFML-2.2-osx-clang-universal.tar.gz -C SFML --strip-components=1
	mv SFML/extlibs/freetype.framework SFML/Frameworks/
	rm -rf "SFML-2.2-osx-clang-universal.tar.gz"

ldenv:
	@echo export $(LDENV)


re:		fclean all

.PHONY:		re all clean fclean

.cpp.o:
	@$(CC) $(CFLAGS) -std=c++11 -o $@ -c $< \
	&& (printf "\r \033[0;0m%-30s\033[1;30m -->>\t\033[0;31m$@\033[0;0m" "$<" \
	&& printf "            \r") \
	|| (printf "\033[0;0m%-30s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
		&& exit 1)
