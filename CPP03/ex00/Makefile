# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 15:20:00 by dde-maga          #+#    #+#              #
#    Updated: 2024/12/27 12:27:24 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Aaaaand..._OPEN!

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC =  main.cpp ClapTrap.cpp

MAIN = main.cpp

SRCOBJ = obj/
OBJ = $(addprefix $(SRCOBJ), $(notdir $(SRC:.cpp=.o)))

HEADERS = ClapTrap.hpp

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