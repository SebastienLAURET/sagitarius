CC=g++
CFLAGS=-W -Wall -Werror
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

BIN_FOLDER=./bin
NAME=${BIN_FOLDER}/test

SRC_FOLDER=./src
FILE=${SRC_FOLDER}/main.cpp
OBJ= $(FILE:.cpp=.o)

all: $(NAME)

${NAME}: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: clean fclean all re
