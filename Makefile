NAME=fract_ol
CC=gcc
CFLAGS=-I$(INC_DIR)

OBJ_DIR=obj
SRC_DIR=src
INC_DIR=includes

_INC = test.h
INC = $(patsubst %, $(INC_DIR)/%, $(_INC))

_OBJ = test.o main.o
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o

fclean:
	rm -f $(OBJ_DIR)/*.o $(NAME)

re: fclean all