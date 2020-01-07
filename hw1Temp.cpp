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
#include <vector>
using namespace std;

int main() 
{
    ifstream myFile;
    string fileName;
    
    int *dynamArray;
    int count;
    int num;
    
    int min = 30; //random high number
	int temp;
    
    vector<int> x;  
    vector<int> y;  

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
            //cout << "Reading data from file. \n";
	        dynamArray[count] = num;
	        //cout<< num << endl; // Prints our STRING.
	        count++;
        }
    
	myFile.close();
	
	//check array for min distance
	//cout << count;
	

	for (int i = 0; i < count - 1; i++){
	    for(int j = i + 1; j < count; j++){
	        temp = abs(dynamArray[i] - dynamArray[j]);
            
	        if (temp < min){
	            min = temp;
	        }

	    }
	}
	
	
	//finds a pair that corresponds to min.
    for (int i = 0; i < count; i++)
    {
    	for (int j = i + 1; j < count; j++)
    	{
    		temp = abs(dynamArray[i] - dynamArray[j]);
    		if (temp == min)
    		{
    			//push values into vectors arrays.
    			x.push_back(dynamArray[i]);
    			y.push_back(dynamArray[j]);
    		}
    	}
    }
    
	delete[] dynamArray; //delete array
	
	cout << "\nMin distance:" << min << endl;
	//displays number pairs with minimum distance
    for (unsigned int i = 0; i < x.size(); i++)
    {
       	cout << "Two numbers for minimum distance: " << x[i] << " and " << y[i] << endl;
    }
	



    return 0;
}
