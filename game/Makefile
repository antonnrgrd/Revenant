GCC = gcc
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
