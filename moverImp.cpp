/****************************************
@Author: Joseph Cox U00594912
@Def: Project Imp file
*******************************************/
#include "Mover.hpp"

/*contructor to build the mover class object
 * Initialize the vector with the size and initilize the empty stack
 */
Mover::Mover (int size,vector<int>& list){
    boxList = list;
    size = size;
}

//Getters/Setters for maxCount
int Mover::getMaxCount() const{
    return maxCount;
}

void Mover:: setMaxCount(int newCount){
    maxCount = newCount;
}

//Getters/Setters for currentCount
int Mover:: getCurrentCount() const{
    return currentCount;
}

void Mover::setCurrentCount(int newCount){
    currentCount = newCount;
}
int Mover::findGreatestBox(map<int,int>& Store, vector<int> boxList&){
    if(Store.find(key)==Store.end()){
        cout<<"Box Does not exist iterating through list now"<<endl;
        int i = boxList.size();
        int count = 0;
        while(i>0){
            // for debugging
            if(boxList.size()==0){
                cout<<"Error: list size is zero, list does not exist"<<endl;
                return -1;
            }
            // base case is list size is equal to 1
            else if(boxList.size()==1){
                count++;
                Store.insert(i,count);
                return count;

            }
            else{

            }
            i--;
        }
    }
    else{
        return Store.find(key);
    }

     
}

