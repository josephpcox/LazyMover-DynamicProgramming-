#include <stdlib.h>
#include <vector>
#include <stack>
#include <fstream>
#include "Mover.hpp"
#include <sstream> //std::istringstream

using namespace std;

int main(int argc, char const *argv[])
{
    // ifstream readFrom;
    // ofstream writeTo;
    // readFrom.open("input.txt");
    // writeTo.open("output.txt");
    // if(!readFrom.is_open()))
    //     perror("Error while opening input.txt file for reading.\n");
    // if(!writeTo.is_open())
    //     perror("Error while opening output.txt file for writing.\n");

    Mover myMover = Mover(5);
    for(int i = 0; i <= myMover.boxList.size(); i++)
    {
        if(myMover.boxList[i] > myMover.currentBox.top() && 1 >= myMover.boxList[i]){
            myMover.currentBox.pop();
            myMover.currentCount -= 1;
            myMover.currentBox.push(myMover.boxList[i]);
            myMover.currentCount += 1;
        }
        else{
            myMover.currentBox.push(myMover.boxList[i]);
            myMover.currentCount += 1;
        }
        myMover.maxCount = myMover.currentCount;
    }

    //Closing files
    // readFrom.close();
    // writeTo.close();
    return 0;

}

