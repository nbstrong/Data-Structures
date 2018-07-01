/*
Nicholas Strong
CSC 231

The purpose of this program is to demonstrate linear search. We will create an array and fill it with random numbers and then search for
particular numbers in the array.
*/

#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().
#include <cstdlib>		// Used for random number generation.
#include <time.h>       // Used to seed the random number generator.

using namespace std;

// Forward declarations of functions.
void pressAnyKey();
void displayArray(int array[], int length);
void randomizeArray(int array[], int length);
int linearSearch(int array[], int arraySize, int target);
void searchAndDisplayItem(int array[], int arraySize, int target);

// Global variables and constants.
const int LENGTH = 400;				// The length of our demonstration array.
int steps = 0;

int main()
{
	int demo[LENGTH];					// Declare, initialize, and display array.
	displayArray(demo, LENGTH);
	pressAnyKey();						// Pause to take in the experience :-).

	randomizeArray(demo, LENGTH);		// Randomize values in array and display. 
	displayArray(demo, LENGTH);
	pressAnyKey();

	// Use helper function for linear search.
	searchAndDisplayItem(demo, LENGTH, 1);
	searchAndDisplayItem(demo, LENGTH, 12);
	searchAndDisplayItem(demo, LENGTH, 23);
	searchAndDisplayItem(demo, LENGTH, 34);
	searchAndDisplayItem(demo, LENGTH, 45);
	searchAndDisplayItem(demo, LENGTH, 56);
	searchAndDisplayItem(demo, LENGTH, 67);
	searchAndDisplayItem(demo, LENGTH, 78);
	searchAndDisplayItem(demo, LENGTH, 89);
	searchAndDisplayItem(demo, LENGTH, 100);

	pressAnyKey();						// End main function and end program.
	
	return 0;
}

// Display values of array - each on their own line.
void displayArray(int array[], int length)
{
	int i = 0;
	while (i < length)
	{
		cout << array[i] << " " << endl;
		i++;
	}
	cout << endl;
}

// Give a random value to each element of the array.
void randomizeArray(int array[], int length)
{
	srand((unsigned)time(NULL));			// Seed random number generator. 

	int i = 0;
	do
	{
		array[i] = rand() % 100 + 1;		// A random number in the range of 1 to 100 is assigned.
		i++;
	} while (i < length);
}

int linearSearch(int array[], int arraySize, int target)
{
	steps = 0;
	steps += 2; // index = 0, index++ once
	// Go through each index, one at a time sequentially and check to see if the index's value is the target.
	for (int index = 0; index < arraySize; index++)
	{
		steps += 3; // array[index]==target, index < arraysize, index++
		if (array[index] == target)
		{
			steps++; // return value
			return index;		// Return the index of the found target.
		}
	}
	steps++; // return value
	return -1;					// Return -1 as a flag to indicate that the target was not found.
}

void searchAndDisplayItem(int array[], int arraySize, int target)
{
	// Search for some selected values in our array and display results.
	int index = linearSearch(array, arraySize, target);
	if (index >= 0)
	{
		cout << "The value " << target << " was found at index " << index << ".\n";
		cout << "Step count to find " << target << " is " << steps << endl;
	}
	else
	{
		cout << "The value " << target << " was not found in the array.\n";
		cout << "Step count to find " << target << " is " << steps << endl;
	}
}

// Utility functions.
// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();					// Waits and gets next character entered.	
}