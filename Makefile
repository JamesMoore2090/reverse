reverse: reverse.o
	g++ -o reverse reverse.o
reverse.o: reverse.cpp
	g++ -c reverse.cpp
