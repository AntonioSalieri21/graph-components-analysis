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


int Graph::Component::getDiameter()
{

	for (int i = 0; i < members.size(); i++)
	{
		Vertex* vertex = members.at(i);
		if (vertex->eccentricity == -1)
		{
			vertex->eccentricity = findEccentricity(i);
			reset();
			/*for (auto vertex : members)
			{
				vertex->eccentricity = findEccentricity(vertex);
				reset();
			}
			break;*/
		}
	}

	int max = members.at(0)->eccentricity;
	for (auto vertex : members)
	{
		if (vertex->eccentricity > max) max = vertex->eccentricity;
	}
	return max;
}

int Graph::Component::getRadius()
{
	for (int i = 0; i < members.size(); i++)
	{
		Vertex* vertex = members.at(i);
		if (vertex->eccentricity == -1)
		{
			vertex->eccentricity = findEccentricity(i);
			reset();

		}
	}

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
	start->color = 1;
	Vertex* current = start;


	while (!q.empty())
	{
		current = q.front();
		q.pop();
		for (auto neighbour : current->neighbours)
		{
			if (neighbour->color != 1)
			{
				pathDistance.at(neighbour->index) = pathDistance.at(current->index) + 1;
				neighbour->color = 1;
				q.push(neighbour);
			}
		}

		//Parallel execution

		/*#pragma omp parallel num_threads(NUM_THREADS)
{

  int thread_num = omp_get_thread_num();
  int threads = omp_get_num_threads();

  for (int i = thread_num; i < current->neighbours.size(); i += threads)
  {
	Vertex* neighbour = current->neighbours.at(i);


	if (neighbour->color != 1)
	{
	  pathDistance.at(neighbour->index) = pathDistance.at(current->index) + 1;
	  neighbour->color = 1;

	  #pragma omp critical
	  {
		q.push(neighbour);
	  }
	}
  }*/

	}

	//Parallel max distance calculation
	//
	//int max = pathDistance.at(current->index);
/*#pragma omp parallel
	{
		int thread_num = omp_get_thread_num();
		int threads = omp_get_num_threads();

		int i_max = max;

		for (int i = thread_num; i < members.size(); i += threads)
			if (pathDistance.at(i) > max) max = pathDistance.at(i);

		max = i_max;
	}

	return max;*/

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
