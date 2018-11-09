OBJS=moveImp.o 
CC=g++ -std=c++14
FLAGS= -Wall -c -g

help: $(OBJS)
	$(CC) -o move $(OBJS) 

moveImp.o: moveImp.cpp move.hpp
		$(CC) $(FLAGS) moveImp.cpp

clean:
	rm -r *.o help

it:
	./move