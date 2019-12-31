#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream myFile;
    string fileName;
    
    int *dynamArray;
    int count;
    int num;
   cout << "Enter input file name: ";
   cin >> fileName;
   myFile.open(fileName.c_str());

   while(myFile >> num ) // To get you all the lines.
        {
            cout << "Reading data from file. \n";
	        count++;
	        
        }
    dynamArray = new int[count];
    myFile.close();
    myFile.open(fileName.c_str());
    count = 0;
    while(myFile >> num ) // To get you all the lines.
        {
            cout << "Reading data from file. \n";
	        dynamArray[count] = num;
	        cout<< num << endl; // Prints our STRING.
	        count++;
        }
    
	myFile.close();
	
	delete[] dynamArray;
	cout << "\n is closed";
   
    return 0;
}
