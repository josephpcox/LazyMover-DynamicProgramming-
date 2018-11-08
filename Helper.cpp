#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

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

int findGreatest(int array[], int size, vector<int>& myBoxes, int index){
  int currentIndex = index;
  int arraySize = size;
  int max_count = 0;
  int count = 0;

  if(index < size - 1){
    findGreatest(array, size, myBoxes, index + 1);
  }

  if(&array[currentIndex + 1] == NULL && myBoxes[currentIndex] == -1){
    max_count = max_count + 1;
    myBoxes[currentIndex] = max_count;
  }

  else if(isSmallest(array, currentIndex, arraySize) == true && myBoxes[currentIndex] == -1){
    max_count = max_count + 1;
    myBoxes[currentIndex] = max_count;
  }

  else if(myBoxes[currentIndex + 1] != -1 && myBoxes[currentIndex] == -1){
    for(int i = currentIndex + 1; i < size; i++){
        if(array[currentIndex] >= array[i]){
          if(myBoxes[i] > count){
            count = myBoxes[i];
          }
        }
    }
    myBoxes[currentIndex] = count + 1;
  }

  else{
    for(int i = currentIndex; i < size; i++){
      if(array[i] >= array[i + 1]){
        count = count + 1;
      }
    }
    myBoxes[currentIndex] = count + 1;
  }

  return mostBoxes(myBoxes);

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
  vector<int> myBoxes(size2, -1);

  //Making sure that the initization above works for selected test case.
  cout << "Testing sentinal value initization before function call." << endl;
  for(vector<int>::iterator start = myBoxes.begin(); start != myBoxes.end(); ++start){
    cout << "Value: " << *start << endl;
  }

  //function call on the selected test case.
  findGreatest(array2, size2, myBoxes, 0);

  //Making sure that all potential sequence of boxes are correct despite returning the correct
  //max number of boxes able to pick up.
  cout << "\nPrinting out the vector's contents after calling findGreatest()." << endl;
  for(vector<int>::iterator start = myBoxes.begin(); start != myBoxes.end(); ++start){
    cout << "Value: " << *start << endl;
  }

  //Greatest number of boxes possible within given case.
  cout << "\nThe greatest number of boxes able to pick up is: " << mostBoxes(myBoxes) << endl;

  return 0;
}
