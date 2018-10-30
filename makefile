OBJS= mover.o moverImp.o 
CC=g++ -std=c++14
FLAGS= -Wall -c -g

move: $(OBJS)
	$(CC) -o move $(OBJS) 

Mover.o: Mover.cpp
		$(CC) $(FLAGS) Mover.cpp

MoverImp.o: MoverImp.cpp Mover.hpp
		$(CC) $(FLAGS) CardImp.cpp
clean:
	rm -r *.o move