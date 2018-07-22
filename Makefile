CC=g++
CFLAGS=-W -Wall -Werror -std=c++11
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++11

NAME=test

SRC_FOLDER=./src
FILE=${SRC_FOLDER}/planet.cpp \
	${SRC_FOLDER}/player.cpp \
	${SRC_FOLDER}/Univairse.cpp \
	${SRC_FOLDER}/ViewFinder.cpp \
	${SRC_FOLDER}/Arrow.cpp \
	${SRC_FOLDER}/main.cpp

OBJ=$(FILE:.cpp=.o)

all: $(NAME)

${NAME}: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(BIN_FOLDER)

re: fclean all

.PHONY: clean fclean all re
