#include <iostream>
#include "Graph.h"
#include <ctime>
using namespace std;


int main()
{
	Graph g;

	time_t startTime = time(NULL);

	g.readGraphFromFile("Graf1.txt");

	
	time_t readTime = time(NULL);
	cout << "Read time: " << readTime - startTime << endl << endl;

	Graph::Component* comp = g.getLargestComponent();

	time_t endTime = time(NULL);
	
	cout << "Count time: " << endTime - readTime << endl;

	cout << "All time: " << endTime - startTime << endl << endl;

	return 0;
}