#include "Graph.h"

void Graph::Component::printEccentricities()
{
	for (auto vertex : members)
		cout << vertex->id << "   " << vertex->eccentricity << endl;


}


void Graph::Component::reset()
{

#pragma omp parallel for
	for (int i = 0; i < members.size(); i++)
		members.at(i)->color = 0;

}

void Graph::Component::fillEccentricities()
{
#pragma omp parallel for num_threads(NUM_THREADS)
	for (int i = 0; i < members.size(); i++)
	{
		Vertex* vertex = members.at(i);
		if (vertex->eccentricity == -1)
		{

			vertex->eccentricity = findEccentricity(i);


		}
	}

}

int Graph::Component::getDiameter()
{
	//fillEccentricities();
	CUDAFillEccentricities();
	int max = members.at(0)->eccentricity;
	for (auto vertex : members)
	{
		if (vertex->eccentricity > max) max = vertex->eccentricity;
	}
	return max;
}

int Graph::Component::getRadius()
{

	fillEccentricities();

	int min = members.at(0)->eccentricity;

	for (auto vertex : members)
	{
		if (min > vertex->eccentricity) min = vertex->eccentricity;
	}
	return min;

}

int Graph::Component::findEccentricity(int startId)
{
	return findPathBFS(startId);

}
int Graph::Component::findPathBFS(int startId)
{
	vector<int> pathDistance;
	pathDistance.assign(members.size() + 1, -1);
	pathDistance.at(startId) = 0;
	queue<Vertex*> q;
	Vertex* start = members.at(startId);
	q.push(start);
	
	Vertex* current = start;


	while (!q.empty())
	{
		current = q.front();
		q.pop();

		int size = current->neighbours.size();

		for (auto& neighbour : current->neighbours)
		{
			const int neighbourIndex = neighbour->index;
			if(pathDistance.at(neighbourIndex) == -1)
			{
				pathDistance.at(neighbourIndex) = pathDistance.at(current->index) + 1;
				q.push(neighbour);
			}
		}

	}
	return pathDistance.at(current->index);	

}



void Graph::Component::print()
{
	for (auto member : members)
	{
		cout << member->id;
		for (auto neighbour : member->neighbours)
			cout << "   " << neighbour->id;

		cout << endl;
	}
}

