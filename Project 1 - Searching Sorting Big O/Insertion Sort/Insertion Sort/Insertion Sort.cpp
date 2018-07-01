// Nicholas Strong
// Insertion Sort Source for Project I
// Introduction to Data Structures and Algorithms

#include <iostream>
#include <cstdlib>		// Used for random number generation.
#include <time.h>       // Used to seed the random number generator.
#include <conio.h>		// Used for getch().

using namespace std;

void insertion_sort(int arr[], int length);
void randomizeArray(int array[], int length);	// Used functions from previous examples
void displayArray(int array[], int length);		
void pressAnyKey();
void timeSort(int array[], int length); // Sort and time it

const int length = 10000; // length of array
clock_t startTime, endTime; // Define variables for timing

int main() {

	int data[length]; // init array

	randomizeArray(data, length);
	displayArray(data, length);
	timeSort(data, length);
	displayArray(data, length);

	// Display algorithm's running time as difference between starting and ending time. 
	cout << "Insertion sort time for an array of "
		<< length
		<< ": "
		<< ((float)endTime - (float)startTime) / CLOCKS_PER_SEC * 1000
		<< " milliseconds."	// On my machine, CLOCKS_PER_SEC is equal to 1000 and 
							// thus milliseconds is the correct unit.
		<< endl;

	return 0;
}

void insertion_sort(int array[], int length) {
	int j, temp;								//initialize j and temp

	for (int i = 0; i < length; i++) {
		j = i;									// set j = i	

		while (j > 0 && array[j] < array[j - 1]) {  // while j > 0 AND array[j] is less than the array before it
			temp = array[j];						// set temp equal to the array[j]
			array[j] = array[j - 1];				// set the array[j] equal to the one before
			array[j - 1] = temp;					// set the one before equal to temp
			j--;								// decrement j
		}
	}
}

void randomizeArray(int array[], int length)
{
	srand((unsigned)time(NULL));			// Seed random number generator. 

	int i = 0;
	do
	{
		array[i] = rand() % length + 1;		// A random number in the range of 1 to length is assigned.
		i++;
	} while (i < length);
}

// Display values of array - each on their own line.
void displayArray(int array[], int length)
{
	int i = 0;
	while (i < length)
	{
		cout << array[i] << " ";
		i++;
	}
	cout << endl;
	pressAnyKey();
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();					// Waits and gets next character entered.	
}

void timeSort(int array[], int length)
{
	// Time array sort.
	startTime = clock();			// Get starting time.
	insertion_sort(array, length);	// Sort array.
	endTime = clock();				// Get ending time.
}