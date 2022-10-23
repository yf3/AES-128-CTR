CC = gcc
BIN_NAME = run
BIN_DIR = ./bin
OBJ_DIR = ./obj
SRC_DIR = ./
INC_DIR = ./
CFLAGS = -std=c99 -g -I$(INC_DIR)/
ALL_SRCS = $(wildcard $(SRC_DIR)/*.c)
ALL_OBJS = $(ALL_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
.PHONY: clean

$(BIN_DIR)/$(BIN_NAME): $(ALL_OBJS)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -r $(BIN_DIR)/* $(OBJ_DIR)/*