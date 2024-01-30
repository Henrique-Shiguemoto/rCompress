COMPILER=gcc
COMPILER_FLAGS=-g -Wall -Wextra -pedantic -std=c11 -Wno-unused-parameter
BIN=main.exe
SRC=main.c rCompress.c
DEBUGGER=gdb 

all:
	$(COMPILER) $(COMPILER_FLAGS) -o $(BIN) $(SRC)

debug:
	$(DEBUGGER) $(BIN)

run:
	$(BIN)

clean:
	del *.o *.exe