OBJS=moveImp.o 
CC=g++ -std=c++14
FLAGS= -Wall -c -g
MAKEIT = make run

move: $(OBJS)
	$(CC) -o move $(OBJS) 

moveImp.o: moveImp.cpp move.hpp
		$(CC) $(FLAGS) moveImp.cpp

clean:
	rm -r *.o move 

cleanAll:
	rm -r *.o move output.txt

run:
	./move

it:
	$(MAKE)
	$(MAKEIT) 