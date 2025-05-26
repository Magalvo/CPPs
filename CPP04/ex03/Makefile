# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 10:21:01 by dde-maga          #+#    #+#              #
#    Updated: 2025/01/07 11:38:26 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

MAIN = main.cpp

SRCOBJ = obj/
OBJ = $(addprefix $(SRCOBJ), $(notdir $(SRC:.cpp=.o)))

HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp

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