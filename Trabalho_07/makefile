CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=


SOURCES=*.c 
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=Trabalho_07_diego_parente


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
