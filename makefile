OBJS= mover.o moverImp.o 
CC=g++ -std=c++14
FLAGS= -Wall -c -g

move: $(OBJS)
	$(CC) -o move $(OBJS) 

mover.o: mover.cpp
		$(CC) $(FLAGS) mover.cpp

moverImp.o: moverImp.cpp mover.h
		$(CC) $(FLAGS) CardImp.cpp
clean:
	rm -r *.o move