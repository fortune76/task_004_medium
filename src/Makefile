GC=gcc
FLAGS=-Wall -Wextra -Werror
BIN=../bin/

all: find_duplicates

find_duplicates: find_duplicates.c utils.c
	$(GC) $(FLAGS) find_duplicates.c utils.c -o $(BIN)find_duplicates

clean: 
	rm -f $(BIN)*

rebuild:
	clean all