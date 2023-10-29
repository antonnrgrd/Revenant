GCC = gcc
csrc = $(wildcard src/*.c)
IDIR = headers
#OBJS := $(patsubst %.c, build/%.o, $(SRC))
#OBJ_MAIN = build/main.o

#Note- always put -lpanel flag before the -lncurses flag, otherwise, it might yield some compilation issues
#CFLAGS = -I$(IDIR)  -std=c17 -ggdb -Wall -Wshadow -Wextra -pedantic -lm  -lpanel -lncurses  -g 

CFLAGS = -I$(IDIR)  -std=c17 -ggdb -w -lm  -lpanel -lncurses  -g 
.PHONY: RUN clean 

all: 
	mkdir -p build
	make revenant

revenant: $(csrc)
	$(GCC) -o $@ $^ $(CFLAGS)



clean:
	rm -rf output 
