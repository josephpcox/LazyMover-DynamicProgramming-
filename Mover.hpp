#ifndef MOVER_H
#define MOVER_H

#include <stdlib.h>
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>

using namespace std;

struct Mover{
    //Instance variables
    vector<int> boxList;
    stack<int> currentBox;
    int maxCount;
    int currentCount;
    int size;
    

    //Constructor
    Mover (int size);

    //Destructor
    ~Mover(){
        cout<<"Killed mover instance"<<endl;
    };

    //Getters/Setters for maxCount
    int getMaxCount()const;

    void setMaxCount(int);

    //Getters/Setters for currentCount
    int getCurrentCount()const;

    void setCurrentCount(int);
};


#endif
