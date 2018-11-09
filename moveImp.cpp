#include <sstream>
#include <fstream>
#include <string>
#include "move.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  // PLEASE DO NOT EDIT: This makes sure that the files can be read and instreamed 
  /***************************************************************************/
  ifstream input_file("input.txt"); // open the input file
  if (!input_file.is_open()) 
  {   // checking for a successful opening and return 1 if the open fails 
      cout << "Input file could not be opened! Terminating!" << endl;
      return 1;
  }
  ofstream output_file("output.txt"); // open the output file
  if (!output_file.is_open()) 
  {   // checking for a successful opening and return 1 if the open fails
      cout << "Output file could not be opened! Terminating!" << endl;
      return 1;
  }
  /***************************************************************************/

  int num = 0;
  stringstream ss;
  string line;
  bool first = true;
  int count=1;
  while (count != 0)  
  {
    if(first == true)
    {
      first = false;
      getline(input_file,line);
      ss << line;
      ss >> count;
      cout<<"number of problems is: "<< count <<endl;
      ss<< "";
      ss.clear();
      continue;
    }
    else
    {
      getline(input_file,line);
      ss << line;
      ss >> num;
      cout<<"The size of the vector is: "<< num <<endl;
      ss<<"";
      ss.clear();
      vector<int> myBoxList(num, -1);
      getline(input_file,line);
      cout<<"The line is:"<<line<<endl;
      ss<<line;
      for(int i = 0;i<myBoxList.size();i++)
      {
        ss >> num;
        ss<<"";
        ss.clear();
        myBoxList[i]=num;
      }
      cout<<"answer is: "<<findGreatestHelper(myBoxList,myBoxList.size())<<"\n"<<endl;
      cout<<"myBoxSize is:"<<myBoxList.size()<<endl;
      for(int i =0;i<myBoxList.size();i++)
      {
        cout<<"Vector at "<< i+1<<":"<< myBoxList[i]<<endl;
      }

    }
    count--;
  }
  return 0;
}
