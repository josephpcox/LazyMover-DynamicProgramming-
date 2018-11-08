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



int main (){
    // make sure that the files can be read and instreamed 
    /***************************************************************************/
    ifstream input_file("input.txt"); // open the input file
    if (!input_file.is_open()) { // check for successful opening
        cout << "Input file could not be opened! Terminating!" << endl;
        return 1;
    }
    ofstream output_file("output.txt"); // open the output file
    if (!output_file.is_open()) { // check for successful opening
        cout << "Output file could not be opened! Terminating!" << endl;
        return 1;
    }
    /***************************************************************************/

    // read in the stream until the EOF
    stringstream ss;
    string line;
    bool firstTime=true;
    int numProblems=0;
    vector<int> > problemSet();
    while (input_file) {
        // we need to know how many objects need to be created 
        if(firstTime == true){
            getline(input_file,line);
            ss << line;
            ss >> numProblems;
            cout<<"This is the number of objects that need to be created for this file "<<numProblems<<endl;
            firstTime = false;
        }
        // Read a Line from File 
        getline(input_file, line); 
        // Print line in Console to make sure the line is correct 
        cout << line << endl; 
    }


    // make sure we close the files when we are finished
    input_file.close();
    output_file.close();
    cout << "Done!" << endl;
    return 0;
}
