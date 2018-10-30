#include <stdlib.h>
#include <vector>
#include <stack>
#include <fstream>
#include <mover.h>
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

    myMover = Mover();
    currentCount = 0;
    maxCount = 0;
    myMover.boxList.push_back()
    for(i = 0; i < myMover.boxList.size(); i++)
    {
        if(myMover.boxList[i] > myMover.currentBox.top() && MatrixRow >= myMover.boxList[i]){
            myMover.currentBox.pop();
            currentCount -= 1;
            myMover.currentBox.push(boxList[i]);
            currentCount += 1;
        }
        else{
            myMover.currentBox.push(boxList[i]);
            currentCount += 1;
        }
        maxCount = currentCount;
    }

    //Closing files
    // readFrom.close();
    // writeTo.close();
    return 0;

}

