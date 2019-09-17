CC=clang++ 
CFLAGS=-Wall -Wextra -g -std=c++11
HEADERS = parser.h node.h interpreter.h
OBJECTS = main.o parser.o node.o interpreter.o

default: interpreter

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

interpreter: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS)
	rm -f interpreter
