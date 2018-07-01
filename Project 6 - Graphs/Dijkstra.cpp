// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <limits.h>		// Used for INT_MAX
#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().

using namespace std;

// controls how many vertices in the graph
const int VERTICES = 9;
 
int minDistance(int distance[], bool shortestPathFoundSet[]);
void printSolution(int distance[], int n);

void pressAnyKey();

// function to determine 
int minDistance(int distance[], bool shortestPathFoundSet[])
{
	// min = int_max and initialize minIndex
   int min = INT_MAX, minIndex;
	
	// 0 < vertices, iterate through array
   for (int v = 0; v < VERTICES; v++)
   {
	   // if shortest path found is false and distance v is less than or equal to min
     if ( (shortestPathFoundSet[v] == false) && (distance[v] <= min) )
	 {
		 // min is now distance v
         min = distance[v], minIndex = v;
	 }
   }
	// return array index of min
   return minIndex;
}
 
// function for, obviously, printing solution
void printSolution(int distance[], int n)
{	
	cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < VERTICES; i++)
	{
		cout << i << "\t" << distance[i] << endl;
	}
}
 
 // Main function that runs the process
void dijkstra(int graph[VERTICES][VERTICES], int src)
{
	 // initialize distance as 9 length array
     int distance[VERTICES];
	 // initialize shortestpathfoundset as 9 length array
     bool shortestPathFoundSet[VERTICES];  
     
	 // for 0 < 9, so 9 times
     for (int i = 0; i < VERTICES; i++)
	 {
		// initialize array as maximum distance an int can be
        distance[i] = INT_MAX;
		// initialize array as all false values
		shortestPathFoundSet[i] = false;
	 }
	      
		// distance[0] = 0  
     distance[src] = 0; 
     
	 // for 0 < 8
     for (int count = 0; count < VERTICES-1; count++)
     {     
		
		// int minDistance(int distance[], bool shortestPathFoundSet[])
		// u is shortest path found
       int u = minDistance(distance, shortestPathFoundSet); 
		// array [u] is true if shortest path
       shortestPathFoundSet[u] = true; 
       
	   // for 0 < 9
       for (int v = 0; v < VERTICES; v++)
	   {
		 // if not shortest path found and graph uv and distance u is not equal to int_max
		 // and distance u plus distance uv is less than distance v
         if (!shortestPathFoundSet[v] && graph[u][v] && distance[u] != INT_MAX 
                                       && distance[u] + graph[u][v] < distance[v])
		 {
            distance[v] = distance[u] + graph[u][v];
		 }
	   }
     } 
     
	 // print shortest path found
     printSolution(distance, VERTICES);
}
 
int main()
{
	// Adjacency matrix. Two dimensional array
	int graph[VERTICES][VERTICES] = 
		{		
		//	 0   1   2   3   4   5   6   7   8
			{0,  4,  0,  0,  0,  0,  0,  9,  0},	// 0                       
			{4,  0, 10,  0,  0,  0,  0, 13,  0},	// 1               
			{0, 10,  0,  8,  0,  4,  0,  0,  2},    // 2               
			{0,  0,  8,  0,  9, 15,  0,  0,  0},	// 3               
			{0,  0,  0,  9,  0, 10,  0,  0,  0},	// 4               
			{0,  0,  4, 15, 10,  0,  2,  0,  0},	// 5               
			{0,  0,  0,  0,  0,  2,  0,  1,  6},	// 6               
			{9, 13,  0,  0,  0,  0,  1,  0,  8},	// 7               
			{0,  0,  2,  0,  0,  0,  6,  8,  0}		// 8
		};
	
	// void dijkstra(int graph[VERTICES][VERTICES], int src)
    dijkstra(graph, 0);
 
	pressAnyKey();

    return 0;
}

void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					
}
