CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = processes
SRC = process.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
