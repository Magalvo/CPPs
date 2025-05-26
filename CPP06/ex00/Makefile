NAME = ex00

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC =   main.cpp ScalarConverter.cpp

MAIN = main.cpp

SRCOBJ = obj/
OBJ = $(addprefix $(SRCOBJ), $(notdir $(SRC:.cpp=.o)))

HEADERS = ScalarConverter.hpp

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