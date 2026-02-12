.PHONY: all clean

TARGET = main
SRC = main.c src/matrix.c src/equations.c src/basics.c src/var_switch.c src/cond.c src/loop.c src/array.c src/recursive.c src/string.c src/struct.c src/file.c
FLAGS = -lm -fsanitize=address -lpub

all:
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)