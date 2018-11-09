/***************************************************************************************************************************************************************************************************************************************/
// Authors: Group 3                            Date:11/9/18
// Joseph Cox
// Adrian Borrego
// Ricardo Montanez                            move.hpp: doc def- header file contains all the functions necessary to solve a single line/problem-set of the lazy mover project from the input.xtx
/***************************************************************************************************************************************************************************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
/***************************************************************************************************************************************************************************************************************************************/
// HEALPER FUNCTION-mostBoxes: Helper function that searches the vector for greatest number of boxes,when the recusrive
//                             function has 100& finished, we call mostBoxes() to get the best possible answer. It takes 
//                             a vector and looks looks for the most boxes it in the solved recursive set
/***************************************************************************************************************************************************************************************************************************************/
int mostBoxes(vector<int>& myBoxes){
  vector<int>::iterator start = myBoxes.begin();
  vector<int>::iterator end = myBoxes.end();

  int max_value = *start;

  for(; start != end; ++start){
    if(*start > max_value){
      max_value = *start;
    }
  }

  return max_value;
}
/***************************************************************************************************************************************************************************************************************************************/
// HELPER FUNCTION- isSmallest: Helper function for  specific cases:
//                  1) when the current box is not the last box in the array sequence
//                  2) it is smaller than all of the boxes to the right side of recusrive call.
/***************************************************************************************************************************************************************************************************************************************/
bool isSmallest(vector<int>& boxList, int index, int size){
  bool isSmaller = false;
  int currentBox = boxList[index];

  for(int i = index; i < size; i++){
    if(currentBox < boxList[i]){
      isSmaller = true;
    }
    else{
      isSmaller = false;
      break;
    }
  }
  return isSmaller;
}
/***************************************************************************************************************************************************************************************************************************************/
//MEMOIZED RECURSIVE FUNCTION- findGreatest: function to find greatest number of boxes, called by helper function findGreatestHelper()
//                                           it takes in a boxList, which is the problem set and it also takes in myBoxes vector which is the 
//                                           storge for the "memoization" this is so that we do not have to keep recursing all the way through 
//                                           list only through the parts that are not solved
/***************************************************************************************************************************************************************************************************************************************/
int findGreatest(vector<int>& boxList, int size, vector<int>& myBoxes, int index){
  
  int currentIndex = index;                                                                                                // Variables needed throught logic.
  int arraySize = size;
  int max_count = 0;
  int count = 0;

  
  if(index < size - 1) findGreatest(boxList, size, myBoxes, index + 1);                                                    // NOTE: single line if no need for brackets:1st we must call the recusrive call up until the last index in the array before performing any base cases.   
                                                                                                                                          
                       
 
  if(&boxList[currentIndex] + 1 == NULL && myBoxes[currentIndex] == -1){                                                   // BASE CASE 1: the current sequence of recusrive call is only one box, the last index of the array given.
    max_count = max_count + 1;
    myBoxes[currentIndex] = max_count;
  }


 
  else if(isSmallest(boxList, currentIndex, arraySize) == true && myBoxes[currentIndex] == -1){                            // BASE CASE 2: the current sequence of recusrive call within starting and ending indexes of array and all possible boxes to the right of currentIndex ar greater.
    max_count = max_count + 1;                                                                                             // Therefore, it can only pick up itself.
    myBoxes[currentIndex] = max_count;
  }

  
  else if(myBoxes[currentIndex + 1] != -1 && myBoxes[currentIndex] == -1){                                                 // BASE CASE 3: The current sequence of recusrive call within starting and ending indexes of array, and the sequence to the right of currentBox has been already solved
    for(int i = currentIndex + 1; i < size; i++)
    {                                                                                                                      // by the previous recursive call and exisits in the vector.
        if(boxList[currentIndex] >= boxList[i])                                                                            // Double conditional to make sure a current max count is kept because there might be mutiple boxes which the the currentBox is greater than but are further down the sequence.
        {                                                                                                                  // Goes through entire sequence to check if the current box is greater than the next box in the sequence
          if(myBoxes[i] > count) count = myBoxes[i];
        }
    }
    myBoxes[currentIndex] = count + 1;
  }

  else{                                                                                                                    // If non of the above cases are true, perform the naive alogirthm to find the greatest number of boxes possible.
    for(int i = currentIndex; i < size; i++){
      if(boxList[i] >= boxList[i + 1]){
        count = count + 1;
      }
    }
    myBoxes[currentIndex] = count + 1;
  }
  return mostBoxes(myBoxes);                                                                                               // Call mostBoxes to find the greatest number of possible boxes after vector has been completely filled.
}
/***************************************************************************************************************************************************************************************************************************************/
//HELPER FUNCTION-findGreatestHelper:that will create the vector for the corresponding array of boxes and initialize all values
//                                   to a sentinal value of -1 for conditional checking.
/***************************************************************************************************************************************************************************************************************************************/
int findGreatestHelper(vector<int>& boxList, int size){

  vector<int> myBoxes(size, -1);                                                                                         // A vector is used to store sub-results. It is a replica of the original input array but stores the
  return findGreatest(boxList, size, myBoxes, 0);                                                                        // number of possible boxes starting at each index to the end of the array.

}