# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 15:32:57 by dde-maga          #+#    #+#              #
#    Updated: 2024/12/28 15:32:57 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC =  main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp 

MAIN = main.cpp

SRCOBJ = obj/
OBJ = $(addprefix $(SRCOBJ), $(notdir $(SRC:.cpp=.o)))

HEADERS = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

all: $(NAME)

$(SRCOBJ)%.o: ./%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	@echo "Compiling into executable"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled successfully!"

clean:
	@rm -rf $(SRCOBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable deleted."

re: fclean all