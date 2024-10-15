NAME := clapTrap

CC = c++
CPPFLAGS = -Wall -Wextra -Werror

SRC = main.cpp clapTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) (OBJ) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
