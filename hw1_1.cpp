/*
 * Title: hw1_1.cpp
 * Abstract: This program reads a text file and shows the min distance between two numbers.
 * Author: Wais Robleh
 * ID: 1624
 * Date: 01/04/2020
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
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

    if (myFile >> num)
    {
      count = num;
    }
    dynamArray = new int[count];
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
	int q, r = 0;
	for (int i = 0; i < count - 1; i++){
	    for(int j = i + 1; j < count; j++){
	        temp = dynamArray[i] - dynamArray[j];
            
            temp = abs(temp);
	        if (temp < min && temp > 0){
	            min = temp;
	            x = dynamArray[i];
	            y = dynamArray[j];
	        }
	        if(temp == min && x != dynamArray[i] && x != dynamArray[j] && y != dynamArray[i] && y != dynamArray[j]){
	            q = dynamArray[i];
	            r = dynamArray[j];
	        }
	    }
	}
	
	delete[] dynamArray; //delete array
	
	cout << "\nMin distance:" << min << endl;
	cout << "Two numbers for min distance: " << x << " and " << y << endl;
	
	if(q != 0){
	    cout << "Two numbers for min distance: " << q << " and " << r << endl;
	}


    return 0;
}
