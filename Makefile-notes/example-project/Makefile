CC=gcc
CFLAGS=-Wall -Wextra
SRC_DIR=src
OBJ_DIR=build
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJS)
	gcc $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXEC) $(OBJS)

debug:
	echo "Hello world!"
