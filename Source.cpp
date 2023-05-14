#include "Graph.h"

using namespace std;


int main()
{

	omp_set_num_threads(NUM_THREADS);
	Graph g;

	time_t startTime = time(NULL);

	g.readGraphFromFile("text.txt");

	
	time_t readTime = time(NULL);
	cout << "Read time: " << readTime - startTime << endl << endl;

	Graph::Component* comp = g.getLargestComponent();

	time_t endTime = time(NULL);
	
	cout << "Count time: " << endTime - readTime << endl << endl;

	cout << "Component size: " << comp->members.size() << endl << endl;



	cout << "Diameter of component: " << comp->getDiameter() << endl;

	time_t diameterTime = time(NULL);

	cout << "Time of diameter calculations: " << diameterTime - endTime << endl << endl;



	cout << "Radius of component: " << comp->getRadius() << endl;

	time_t radiusTime = time(NULL);

	cout << "Time of radius calculations: " << radiusTime - diameterTime << endl << endl << endl;

	//comp->printEccentricities();


	cout << "All time: " << radiusTime - startTime << endl << endl;

	return 0;
}