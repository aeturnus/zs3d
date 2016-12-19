PLATFORM = unix
# planned targets: unix, windows, tm4c123

CC = gcc
LD = ld
CFLAGS =-Wall -Wextra
SOURCES = $(wildcard *.c) $(wildcard src/brandonware/*.c) $(wildcard src/platform/$(PLATFORM)/*.c)
EXECUTABLE = zs3d
INCLUDE = inc
OBJDIR = obj

OBJECTS = $(SOURCES:.c=.o)

ifeq ($(PLATFORM),unix)
LIBS = -lSDL2
endif

.c.o:
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -D$(PLATFORM) -c $< -o $(OBJDIR)/$(@F)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) -o $(EXECUTABLE) $(addprefix $(OBJDIR)/,$(notdir $(OBJECTS)))


all: $(EXECUTABLE)
	@echo "Program built"

clean:
	rm -r $(OBJDIR)
	rm $(EXECUTABLE)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

mem: $(EXECUTABLE)
	valgrind --leak-check=yes ./$(EXECUTABLE)

debug: $(EXECUTABLE)
	gdb ./$(EXECUTABLE)
