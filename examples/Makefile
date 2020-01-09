test-example: ../include/asyncTest.hpp ../include/eventLoop.hpp example.cpp
	g++ -std=c++11 -O0 -g -fsanitize=address -I../include example.cpp -o test-example
all: test-example
clean:
	rm -f ./test-example
run: test-example
	./test-example

