# Lazy Mover Project
## Group 3: Joseph Cox Adrian Borrego and Ricardo Montanez

---

## General Overview of the Program

We have two files *move.hpp* and *moveImp.cpp*

1. Move.hpp:
This file contains the recursive function called *findGreatest* that solves each problem set inside the input.txt. It also 
has helper functions that work with it to modulate some of the logic and memoize the algorithm. There are no calsses in this
file, it only contains the necessary functions to solve the problem. The functions are all global.

2. MoveImp.cpp
This file contains the *main()* and reades the input.txt with a string stream and creates an output.txt. The string stream feeds the *findGreatestHealper* function which calls the *findGreatest* function inside of it. It returns an integer with the correct answer to each problem set. The correct answer is then appended to the end of the file with a new line chracter. At the end of the main() function all the files are closed 

---

## Complier Information 

We use the gcc c++14 compiler, however we tested the progam on the student cluster and it works on the student cluster utilizing the *g++ -Wall move.hpp moveImp.cpp* and no warnings or errors have emerged. However a makefile has been provided for convinence. **To use the makefile on the student cluster you must change the CC from *CC=g++ -std=c++14* to *CC=g++* the student cluster does not run c++14 or c++11**

---

## Makefile

This make file has 5 functions that can be exucted in the following way:
1. $make - this will compile the program without running it. 
2. $make run - this will run the program only after make(the above command) has been called
3. $make clean - this will delete all the object files and it will also delete the executable
4. $make cleanAll - this will delte all the objectfiles, the executable and it will delete the output.txt
5. **$make it - this will compile the program and run the program all at once, since the program is ran it will generate an output.txt** 


