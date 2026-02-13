.PHONY: all clean

TARGET = main
SRC = $(shell find . -type f -name '*.c')
FLAGS = -lm -fsanitize=address -lpub

all:
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)