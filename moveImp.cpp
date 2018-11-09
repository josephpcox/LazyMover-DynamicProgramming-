#include <sstream>
#include <fstream>
#include <string>
#include "move.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
/******************************************************************************************************************************/
  // PLEASE DO NOT EDIT: This makes sure that the files can be read and instreamed 
  //                     ifstream the input.txt and ofstream the output.txt if there 
  //                     is something wrong with the files it will terminate the main()
  //                     by returning a 1 and output the cooresponding error message 
  /******************************************************************************************************************************/
  ifstream input_file("input.txt"); // open the input file
  if (!input_file.is_open()) 
  {   // checking for a successful opening and return 1 if the open fails 
      cout << "Input file could not be opened! Terminating!" << endl;
      return 1;
  }
  ofstream output_file("output.txt"); // create the output file
  if (!output_file.is_open()) 
  {   // checking for a successful opening and return 1 if the open fails
      cout << "Output file could not be opened! Terminating!" << endl;
      return 1;
  }
/******************************************************************************************************************************/
  // INITIALIZE VARIABLES: for use thoughout the program stringstream ss is how
  //                       how we input into a vector container that gets passed 
  //                       into a function that will hold the problem set, aka
  //                       the list of numbers that the lazy mover must solve
  //                       string line is for the getline function that will pass 
  //                       its contents into the string stream ss. 
/******************************************************************************************************************************/
  int num = 0;
  stringstream ss;
  string line;
  bool first = true;
  int count=1;
  int answer = 0;
  /******************************************************************************************************************************/
  // LOOP: count is origionally 0 but gets properly initalized in the first if statement
  //       when the flag first is false by default, count gets initilized by the first
  //       line in input.txt file which states how many problem sets their are, after each 
  //       iteration of the loop we subtract 1 from count eventually terminating the loop
  //       when there are no more problem sets to be solved, This ensures that we do not 
  //       put empty strings into vector just in case there is space characters in the input.txt
  //       before the EOF mark.
  /******************************************************************************************************************************/
  while (count != 0)  
  {
    if(first == true)
    {
      first = false;                         // set the flag to false because we do not want to run this line after first iteration
      getline(input_file,line);              // this is the first getline it will read in the number of problem sets to be solved
      ss << line;                            // put the number of problem sets into count, and count will keep track of when to stop
      ss >> count;
      ss<< "";                               // feed an empty sring into the string stream ss and call clear to flush the buffer
      ss.clear();                            // NOTE ss.flush does not flush the buffer, IDK why
      continue;                              // it needs to continue so that the else statment will execute while the counter is at 0 still otherwise 
      /*                                     // else will be skiped and counter will -1 and it will solve 1 less problem set then it should */
    }
    else
    {
      getline(input_file,line);              // get the next line from the input file, place it as a string in line, shoul be line = n1 n2 n3 n4 ... nn as one string
      ss << line;                            // feed the line into the string stream ss
      ss >> num;                             // outout the next space delimited character as an int to num. the next space delmited character is the size of the first problem set
      ss<<"";
      ss.clear();
      vector<int> myBoxList(num, -1);       // initalize a vector to the size of num which is the size of the list we need to create, initilize all the indexes to hold value of -1
      getline(input_file,line);             // this next get line will read all the numbers in the problem set, and then it will be feed into the string stream ss
      ss<<line;
      
      for(int i = 0;i<myBoxList.size();i++) // this loop just places each space delimited character as an int into the vector index of i, where i starts at 1, 
      {
        ss >> num;
        ss<<"";
        ss.clear();
        myBoxList[i]=num;
      }
      answer=findGreatestHelper(myBoxList,myBoxList.size());
      output_file<<answer<<"\n";

    }
    count--;
  }
  input_file.close();
  output_file.close();
  return 0;

}
