CC=gcc
CFLAGS1=-Wall -std=c11 -O3
DIR_BIN=bin

all: $(DIR_BIN)/colors.o $(DIR_BIN)/debug_c.o $(DIR_BIN)/time_code.o $(DIR_BIN)/error_c.o
	echo "compilando... con: $^"

$(DIR_BIN)/colors.o: lib/DebugLibC/colors-C-C-plus-plus/colors.c
	$(CC) $(CFLAGS1) -c $^ -o $@
	
$(DIR_BIN)/debug_c.o: lib/DebugLibC/debug_c.c
	$(CC) $(CFLAGS1) -c $^ -o $@

$(DIR_BIN)/time_code.o: lib/DebugLibC/time_code.c
	$(CC) $(CFLAGS1) -c $^ -o $@

$(DIR_BIN)/error_c.o: lib/DebugLibC/error_c.c
	$(CC) $(CFLAGS1) -c $^ -o $@