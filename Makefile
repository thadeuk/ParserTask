CC=clang++ 
CFLAGS=-Wall -Wextra -g -std=c++11
HEADERS = parser.h node.h interpreter.h 
OBJECTS = parser.o node.o interpreter.o
MAIN = main.o
MAINTEST = test.o

default: interpreter

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

interpreter: $(OBJECTS) $(MAIN)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAIN) -o $@

compileTest: $(OBJECTS) $(MAINTEST)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAINTEST) -o tester

clean:
	rm -f $(OBJECTS)
	rm -f interpreter
	rm -f tester

test: compileTest
	./tester
	@rm -f tester
