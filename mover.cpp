/*
* @Def: Driver class for the algorithms project
* @Author: Joseph Cox U00594912 Ricardo Montanez
* Date: 10/30/18
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
using namespace std;

int main() {

	// initalize the starting variables...
	stringstream ss;
	int comp;

	string line;
	bool firstTime = true;
	int numObjects = 0;
	int size = 0;
	
	// DO NOT TOUCH With out talking to Joseph
	// make sure that the files can be read and instreamed 
	/***************************************************************************/
	ifstream input_file("input.txt"); // open the input file
	if (!input_file.is_open())
	{   // check for successful opening
		cout << "Input file could not be opened! Terminating!" << endl;
		return 1;// if the file cant be open just kill the program
	}
	ofstream output_file("output.txt"); // open the output file
	if (!output_file.is_open())
	{   // check for successful opening
		cout << "Output file could not be opened! Terminating!" << endl;
		return 1; // if the file cant be open just kill the program
	}
	/****************************************************************************/

	// read in the stream until the EOF
	while (input_file)
	{
		// we need to know how many objects need to be created 
		if (firstTime == true)
		{
			getline(input_file, line);
			istringstream ss(line);
			//ss << line;
			ss >> numObjects;
			
			cout << "This is the number of objects that need to be created for this file " << numObjects << endl;
			firstTime = false;
		}
		/* create vectors for each line pair until the very end of the file the first line is the num
		* the numObjects that is extracted from the above if tells us how many times this loop needs to iterate to create the problem set
		* the problem set is a "vector of vectors" in order to pushback we need to push back an entire vector push_back(v)
		*/
		vector<vector<int> > problemSet(numObjects);
		for (int i = 0; i<numObjects; i++)
		{
			// the lines always go in pairs from here on out, the first line is going to be the size of the vector that we need
			// the next line is going to be the list that needs to be put in the vector use getline to retrieve the line
			getline(input_file, line);
			istringstream ss2(line);
			//ss << line;
			ss2 >> size;
			cout << "The size that will be allocated for this vector is... " << size << endl;
			vector<int> v(size);
			/*now we call getline function again and iterate through the charaters of the array converting
			* each charater into an int
			*/
			getline(input_file, line);
			istringstream ss3(line);
			// ss << line; 

			while (ss3 >> comp) { //enters string stream into int var
				cout << (comp) << endl;
				v.push_back(comp);
			}//Should work in place of below code
			
			problemSet.push_back(v); // put v into the problem set
			v.clear(); // destroy the vector and free the memory for the next iteration to use the same variables 
		}
	}
	// make sure we close the files when we are finished
	input_file.close();
	output_file.close();
	cout << "Done!" << endl;
	return 0;
}

