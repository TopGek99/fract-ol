NAME=fract_ol
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) -Ilibft/includes
LDFLAGS=-Llibft -lft -L$(LIB_DIR) -l$(LIB_DIR) -framework OpenGL -framework AppKit

SRC_DIR=src
INC_DIR=includes
LIB_DIR=mlx

_INC = fractol.h
INC = $(patsubst %, $(INC_DIR)/%, $(_INC))

OBJ = fractol.o image.o hooks.o main.o

_LIB = libmlx.a
LIB = $(patsubst %, $(LIB_DIR)/%, $(_LIB))

all: $(NAME)

%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(LIB):
	cd $(LIB_DIR) && make && cd ..

.PHONY: clean

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re: fclean all