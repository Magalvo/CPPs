# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 13:54:15 by dde-maga          #+#    #+#              #
#    Updated: 2024/12/05 17:02:23 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = Contact.cpp PhoneBook.cpp

MAIN = main.cpp

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

HEADERS = Contact.hpp PhoneBook.hpp

all : ${NAME}

${NAME}: ${OBJ} ${HEADERS}
	@echo "Compiling into object files"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled successfuly!"

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted."

fclean : clean
	@rm -rf ${NAME}
	@echo "Executable deleted."

re:
	@make fclean
	@make
