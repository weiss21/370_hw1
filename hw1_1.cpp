#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream myFile;
    string fileName;
    string line;
   cout << "Enter input file name: " << endl;
   cin >> fileName;
   myFile.open(fileName.c_str());
   cout << endl;
   cout<< fileName + " is opened" << endl;
   while(getline(myFile,line).good()) // To get you all the lines.
        {
	        getline(myFile,line); // Saves the line in STRING.
	        cout<<line; // Prints our STRING.
        }
	myFile.close();
	cout << "\n is closed";
   
    return 0;
}
