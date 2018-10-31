#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

/*struct Move{
    vector <int> dolly;
    
    // Constructor
    Mover(){
        
    }
};
*/

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
    bool firstTime = true;
    int numObjects=0;
    while (input_file) {
        // we need to know how many objects need to be created 
        if(firstTime == true){
            getline(input_file,line);
            ss << line;
            ss >> numObjects;
            cout<<"This is the number of objects that need to be created for this file "<<numObjects<<endl;
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