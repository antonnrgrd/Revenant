GCC = gcc

#SRC =  main.c item.c modifier.c strings.c inventory.c u_hash.c  generate.c creature.c test_runs.c game_state.c move_handler.c tiles.c placeholder.c
csrc = $(wildcard src/*.c)
IDIR = headers
#OBJS := $(patsubst %.c, build/%.o, $(SRC))
#OBJ_MAIN = build/main.o
CFLAGS = -I$(IDIR)  -std=c11 -ggdb -Wall -Wextra -pedantic -lm -lncurses -g

.PHONY: RUN clean 

all: 
	mkdir -p build
	make revenant

revenant: $(csrc)
	$(GCC) -o $@ $^ $(CFLAGS)



clean:
	rm -rf output 
