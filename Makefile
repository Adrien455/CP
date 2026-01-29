.PHONY: all clean

TARGET = main
SRC = main.c
FLAGS = -lm 

all:
	$(CC) $(SRC) -o $(TARGET) $(FLAGS) 

clean:
	rm -f $(TARGET)