.PHONY: all clean

TARGET = main
SRC = main.c src/matrix.c src/equations.c src/basics.c
FLAGS = -lm -fsanitize=address

all:
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)