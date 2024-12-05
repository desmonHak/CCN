CC=gcc
CFLAGS1=-Wall -std=c11 -O3
DIR_BIN=bin
CLEAR_COMMAND=del
CLEAR_DIR=rmdir /s /q

all: $(DIR_BIN)/colors.o $(DIR_BIN)/debug_c.o $(DIR_BIN)/time_code.o $(DIR_BIN)/error_c.o
	echo "compilando... con: $^"

$(DIR_BIN)/colors.o: lib/DebugLibC/colors-C-C-plus-plus/colors.c
	$(CC) $(CFLAGS1) -c $^ -o $@

$(DIR_BIN)/error_c.o: lib/DebugLibC/error_c.c $(DIR_BIN)/colors.o
	$(CC) $(CFLAGS1) -c $^ -o $@

$(DIR_BIN)/debug_c.o: lib/DebugLibC/debug_c.c $(DIR_BIN)/error_c.o
	$(CC) $(CFLAGS1) -c $^ -o $@

$(DIR_BIN)/time_code.o: lib/DebugLibC/time_code.c $(DIR_BIN)/debug_c.o
	$(CC) $(CFLAGS1) -c $^ -o $@

build_python:
	python setup.py install

clear_python:
	$(CLEAR_DIR) build dist

clear:
	
	$(CLEAR_COMMAND) $(DIR_BIN)\*.o *.pyd