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
    count = 0; //reset array
    while(myFile >> num ) // To get you all the lines.
        {
            cout << "Reading data from file. \n";
	        dynamArray[count] = num;
	        cout<< num << endl; // Prints our STRING.
	        count++;
        }
    
	myFile.close();
	
	//check array for min distance
	//cout << count;
	int min = 30; //random high number
	int x, y, temp;
	for (int i = 0; i < count; i++){
	    for(int j = i + 1; j < count; j++){
	        temp = dynamArray[i] - dynamArray[j];
            
            if(temp < 0){
                temp *= -1;
            }
	        if (temp < min){
	            min = temp;
	            x = dynamArray[i];
	            y = dynamArray[j];
	        }
	    }
	}
	
	delete[] dynamArray; //delete array
	
	cout << "\nMin distance:" << min << endl;
	cout << "Two numbers for min distance: " << x << " and " << y;
	cout << "\n is closed\n";
   
    return 0;
}
