TARGET = mm
TARGET_LIB = libmm.so
OBJ_PATH = ./obj
INSTALL_PTATH=./

CC = arm-linux-gnueabihf-gcc
CFLAG = -g -Wall -Werror

all: main lib
	$(CC) $(OBJ_PATH)/main.o -o $(OBJ_PATH)/$(TARGET) -L$(OBJ_PATH) -lmm $(CFLAG) -Wl,-rpath=./

main:
	$(shell  mkdir -p $(OBJ_PATH))
	$(CC) -c main.c -o $(OBJ_PATH)/main.o $(CFLAG)

lib:
	$(CC) lib.c -fPIC -shared -o $(OBJ_PATH)/$(TARGET_LIB) $(CFLAG) 

clean:
	rm -rf *.so $(OBJ_PATH)/* $(TARGET) $(TARGET_LIB)
	rm -rf *.log
	rm -rf $(OBJ_PATH)

install:
	cp $(OBJ_PATH)/$(TARGET) $(INSTALL_PTATH)
	cp $(OBJ_PATH)/$(TARGET_LIB) $(INSTALL_PTATH)

.PHONY:
	all main lib clean install
