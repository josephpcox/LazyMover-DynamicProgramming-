#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

//Helper function that searches the vector for greatest number of boxes,
//when the recusrive function has 100& finished, we call mostBoxes() to get the best possible answer.
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

//Helper function for a specific case:
// 1) when the current box is not the last box in the array sequence
// 2) it is smaller than all of the boxes to the right side of recusrive call.
bool isSmallest(int array[], int index, int size){
  bool isSmaller = false;
  int currentBox = array[index];

  for(int i = index; i < size; i++){
    if(currentBox < array[i]){
      isSmaller = true;
    }
    else{
      isSmaller = false;
      break;
    }
  }
  return isSmaller;
}

//Memozied Recursive function to find greatest number of boxes, called by helper function findGreatestHelper()
int findGreatest(int array[], int size, vector<int>& myBoxes, int index){
  //Variables needed throught logic.
  int currentIndex = index;
  int arraySize = size;
  int max_count = 0;
  int count = 0;

  //1st we must call the recusrive call up until the last index in the array before performing
  //any base cases.
  if(index < size - 1){
    findGreatest(array, size, myBoxes, index + 1);
  }

  //Base case 1: the current sequence of recusrive call is only one box, the last index of the array given.
  if(array[currentIndex + 1] == NULL && myBoxes[currentIndex] == -1){
    max_count = max_count + 1;
    myBoxes[currentIndex] = max_count;
  }

  //Base case 2: the current sequence of recusrive call within starting and ending indexes of array and all possible boxes to the right of currentIndex ar greater.
  //Therefore, it can only pick up itself.
  else if(isSmallest(array, currentIndex, arraySize) == true && myBoxes[currentIndex] == -1){
    max_count = max_count + 1;
    myBoxes[currentIndex] = max_count;
  }

  //Base case 3: The current sequence of recusrive call within starting and ending indexes of array, and the sequence to the right of currentBox has been already solved
  //by the previous recursive call and exisits in the vector.
  else if(myBoxes[currentIndex + 1] != -1 && myBoxes[currentIndex] == -1){
    for(int i = currentIndex + 1; i < size; i++){
        //Goes through entire sequence to check if the current box is greater than the next box in the sequence
        if(array[currentIndex] >= array[i]){
          //Double conditional to make sure a current max count is kept because there might be mutiple boxes which the the currentBox is greater than but are further down the sequence.
          if(myBoxes[i] > count){
            count = myBoxes[i];
          }
        }
    }
    myBoxes[currentIndex] = count + 1;
  }

  //If non of the above cases are true, perform the naive alogirthm to find the greatest number of boxes possible.
  else{
    for(int i = currentIndex; i < size; i++){
      if(array[i] >= array[i + 1]){
        count = count + 1;
      }
    }
    myBoxes[currentIndex] = count + 1;
  }

  //Call mostBoxes to find the greatest number of possible boxes after vector has been completely filled.
  return mostBoxes(myBoxes);
}

//Helper function that will create the vector for the corresponding array of boxes and initialize all values
//to a sentinal value of -1 for conditional checking.
int findGreatestHelper(int array[], int size){
  //A vector is used to store sub-results. It is a replica of the original input array but stores the
  //number of possible boxes starting at each index to the end of the array.
  vector<int> myBoxes(size, -1);

  return findGreatest(array, size, myBoxes, 0);
}

int main(int argc, char const *argv[]) {
  /* code */
  //TEST CASES ARRAYS BELOW:
  //Alogirthm is working for all test cases including the two cases from
  //input.txt. All that is left would be to include the reading from input file
  //and output file of each instance and store that into an array to pass into
  //function call.
  int array[6] = {10, 11, 5, 9, 8, 7};
  int size = 6;

  int array1[10] = {29, 20, 30, 18, 35, 26, 28, 40, 8, 39};
  int size1 = 10;

  int array2[20] = {38, 35, 45, 39, 23, 16, 26, 28, 20, 5, 8, 17, 12, 10, 13, 42, 6, 34, 33, 37};
  int size2 = 20;

  int array3[10] = {15, 9, 8, 2, 11, 6, 9, 7, 2, 1};
  int size3 = 10;

  int array4[10] = {29, 20, 30, 18, 35, 26, 28, 40, 8, 39};
  int size4 = 10;
  /////////////////////////////////////////////////////////////////////////////

  //function call on the selected test case.
  //Greatest number of boxes possible within given case.
  cout << "\nThe greatest number of boxes able to pick up is: " << findGreatestHelper(array2, size2) << endl;

  return 0;
}
