# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:20:49 by dde-maga          #+#    #+#              #
#    Updated: 2024/12/10 15:58:28 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fight

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp 

MAIN = main.cpp

SRCOBJ = obj/
OBJ = $(addprefix $(SRCOBJ), $(notdir $(SRC:.cpp=.o)))

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp 

all: $(NAME)

$(SRCOBJ)%.o: ./%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
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