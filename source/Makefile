PLATFORM = unix
CC = gcc
LD = ld
CFLAGS =-Wall -Wextra
SOURCES = $(wildcard *.c)
EXECUTABLE = zs3d
INCLUDE = inc
OBJDIR = obj

OBJECTS = $(SOURCES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o obj/$@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS) 


all: $(EXECUTABLE)
	@echo "Program built"

clean:
	rm *.o $(EXECUTABLE)

test:
	./$(EXECUTABLE)

mem:
	valgrind --leak-check=yes ./$(EXECUTABLE)

debug:
	gdb ./$(EXECUTABLE)
