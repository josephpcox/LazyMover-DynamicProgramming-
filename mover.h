#ifndef MOVER_H
#define MOVER_H

#include <stdlib>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

class Mover{
    //Instance variables
    vector<int> boxList;
    stack<int> currentBox;
    int maxCount;
    int currentCount;
    
    public:
        //Constructor
        Mover (fstream& infile);

        //Destructor
        ~Mover();

        //Getters/Setters for maxCount
        int getMaxCount() const;

        void setMaxCount();

        //Getters/Setters for currentCount
        int getCurrentCount() const;

        void setCurrentCount();
};

#endif
