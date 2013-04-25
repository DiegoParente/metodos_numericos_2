CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=


SOURCES=main.c area.c
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=trabalho_01


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
