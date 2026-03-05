CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = libFS_demo
SOURCES = seymour_testlibFS.c seymour_libFS.c
HEADERS = seymour_libFS.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) seymour_introduction.txt

.PHONY: all run clean
