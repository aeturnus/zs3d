PLATFORM = unix
CC = gcc
LD = ld
CFLAGS =-Wall -Wextra
SOURCES = $(wildcard *.c) $(wildcard src/brandonware/*.c) $(wildcard src/platform/$(PLATFORM)/*.c)
EXECUTABLE = zs3d
INCLUDE = inc
OBJDIR = obj

OBJECTS = $(SOURCES:.c=.o)

.c.o:
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -D$(PLATFORM) -c $< -o $(OBJDIR)/$(@F)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(addprefix $(OBJDIR)/,$(notdir $(OBJECTS)))


all: $(EXECUTABLE)
	@echo "Program built"

clean:
	rm -r $(OBJDIR)
	rm $(EXECUTABLE)

test:
	./$(EXECUTABLE)

mem:
	valgrind --leak-check=yes ./$(EXECUTABLE)

debug:
	gdb ./$(EXECUTABLE)
