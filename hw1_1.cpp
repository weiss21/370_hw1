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
    
    vector<int> x;  //placeholder for first two numbers
    vector<int> y;  //placeholder for second of two numbers

   cout << "Enter input file name: ";
   cin >> fileName;
   myFile.open(fileName.c_str()); //open file

    if (myFile >> num)
    {
      count = num; // first line details count of array
    }
    dynamArray = new int[count]; //initialize dynamic array
    count = 0; //reset array count
    
    while(myFile >> num ) // To get you all the lines.
        {

	        dynamArray[count] = num; //add numbers from file to array
	        count++; //keep track of size in array
        }
    
	myFile.close();
	
	//check array for min distance
	
	for (int i = 0; i < count - 1; i++){
	    for(int j = i + 1; j < count; j++){
	        temp = abs(dynamArray[i] - dynamArray[j]);
            
	        if (temp < min){
	            min = temp;
	        }

	    }
	}
	
	
	//finds a pair that corresponds to min distance.

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
    
	delete[] dynamArray; //delete dynamic array
	
	
	
	cout << "\nMin distance:" << min << endl;
	
	//displays number pairs with minimum distance. Depending on how many is located in each pair
    for (unsigned int i = 0; i < x.size(); i++)
    {
		if(i > 0 && x[i] == x[i - 1] ) //i greater than zero and x value equals than x value to left of vector
		{
			continue;
		} 
		else
       	{
       		cout << "Two numbers for minimum distance: " << x[i] << " and " << y[i] << endl;
       		
       	}
    }
	
    return 0;
}
