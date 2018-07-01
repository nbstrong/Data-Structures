// Nicholas Strong
// Merge Sort Source for Project I
// Introduction to Data Structures and Algorithms

#include <iostream>
#include <cstdlib>		// Used for random number generation.
#include <time.h>       // Used to seed the random number generator.
#include <conio.h>		// Used for getch().

using namespace std;

void merge_sort(int array[], int length, int low, int high);		// Merge sort required two functions
void merge(int array[], int length, int low, int mid, int high);
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
	cout << "Merge sort time for an array of "
		<< length
		<< ": "
		<< ((float)endTime - (float)startTime) / CLOCKS_PER_SEC * 1000
		<< " milliseconds."	// On my machine, CLOCKS_PER_SEC is equal to 1000 and 
							// thus milliseconds is the correct unit.
		<< endl;

	return 0;
}

// Merge sort calls itself and then calls merge at the end.
void merge_sort(int array[], int length, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2; // determine a midpoint of the array
		merge_sort(array, length, low, mid); // begin recursion!
		merge_sort(array, length, mid + 1, high); // more recursion!
		merge(array, length, low, mid, high); // merge them back together
	}
}

// Merge combines the arrays
void merge(int array[], int length, int low, int mid, int high) {
	// allocate temporary dynamically sized array
	int* temp = new int[length]; // Ill be honest I don't fully understand the pointer magic happening here. It took about half an hour to get this line to work.
	for (int i = low; i <= high; i++) {
		temp[i] = array[i];
	}
	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid && j <= high) { // while low is less than mid and mid + 1 is less than high
		if (temp[i] <= temp[j]) { // if temp[i] is less than temp[j]
			array[k] = temp[i]; // set array[k] = temp [i] 
			++i; // increment i
		}
		else { 
			array[k] = temp[j]; // else set array[k] = temp[j]
			++j; // increment j
		}
		++k; // increment k
	}
	while (i <= mid) { // while i is less than mid
		array[k] = temp[i]; // set array[k] = temp[i]
		++k; // increment k and i
		++i;
	}

	// deallocate temp array to prevent memory leak
	delete[] temp;
}

void timeSort(int array[], int length)
{
	// Time array sort.
	startTime = clock();			// Get starting time.
	merge_sort(array, length, 0, length - 1);	// Sort array.
	endTime = clock();				// Get ending time.
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

// Display values of array
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