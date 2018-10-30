/****************************************
@Author: Joseph Cox U00594912
@Def: Project Imp file
*******************************************/
#include "Mover.hpp"

using namespace std;
/*contructor to build the mover class object
 * Initialize the vector with the size and initilize the empty stack
 */
Mover::Mover (int size){
  boxList.resize(size);
}

//Getters/Setters for maxCount
int Mover::getMaxCount() const{
    return this->maxCount;
}

void Mover:: setMaxCount(int newCount){
    this->maxCount = newCount;
}

//Getters/Setters for currentCount
int Mover:: getCurrentCount() const{
    return this->currentCount;
}

void Mover::setCurrentCount(int newCount){
    this->currentCount = newCount;
}