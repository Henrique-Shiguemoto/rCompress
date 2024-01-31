COMPILER=gcc
COMPILER_FLAGS=-g -Wall -Wextra -pedantic -std=c11 -Wno-unused-parameter
BIN=main.exe
SRC=main.c rCompress.c
DEBUGGER=gdb 

all:
	$(COMPILER) $(COMPILER_FLAGS) -o $(BIN) $(SRC)

debug: all
	$(DEBUGGER) $(BIN)

run: all
	$(BIN)

clean:
	del *.o *.exe