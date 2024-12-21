# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 11:03:56 by dde-maga          #+#    #+#              #
#    Updated: 2024/12/21 11:03:56 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = triangularPoint

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = bsp.cpp Point.cpp Fixed.cpp main.cpp

MAIN = main.cpp

SRCOBJ = obj/
OBJ = $(addprefix $(SRCOBJ), $(notdir $(SRC:.cpp=.o)))

HEADERS = Fixed.hpp Point.hpp

all: $(NAME)

$(SRCOBJ)%.o: ./%.cpp
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