BIN_DIR = ./bin
OBJ_DIR = ./obj
CFLAGS = -std=c99
.PHONY: clean

test: $(OBJ_DIR)/test.o $(OBJ_DIR)/aes.o $(OBJ_DIR)/counter_mode.o
	gcc -o $(BIN_DIR)/test $(OBJ_DIR)/test.o $(OBJ_DIR)/aes.o $(OBJ_DIR)/counter_mode.o

$(OBJ_DIR)/test.o: test.c aes.h
	gcc -c $(CFLAGS) test.c -o $(OBJ_DIR)/test.o
$(OBJ_DIR)/aes.o: aes.c aes.h
	gcc -c $(CFLAGS) aes.c -o $(OBJ_DIR)/aes.o
$(OBJ_DIR)/counter_mode.o: counter_mode.c counter_mode.h aes.h
	gcc -c $(CFLAGS) counter_mode.c -o $(OBJ_DIR)/counter_mode.o
clean:
	rm -r $(BIN_DIR)/* $(OBJ_DIR)/*