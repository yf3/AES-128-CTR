BIN_DIR = ./bin
OBJ_DIR = ./obj
C99_FLAG = -std=c99
.PHONY: clean

test: $(OBJ_DIR)/test.o $(OBJ_DIR)/aes.o $(OBJ_DIR)/counter_mode.o
	gcc -o $(BIN_DIR)/test $(OBJ_DIR)/test.o $(OBJ_DIR)/aes.o $(OBJ_DIR)/counter_mode.o

$(OBJ_DIR)/test.o: test.c aes.h
	gcc -c $(C99_FLAG) test.c -o $(OBJ_DIR)/test.o
$(OBJ_DIR)/aes.o: aes.c aes.h
	gcc -c $(C99_FLAG) aes.c -o $(OBJ_DIR)/aes.o
$(OBJ_DIR)/counter_mode.o: counter_mode.c counter_mode.h aes.h
	gcc -c $(C99_FLAG) counter_mode.c -o $(OBJ_DIR)/counter_mode.o
clean:
	rm -r $(BIN_DIR)/* $(OBJ_DIR)/*