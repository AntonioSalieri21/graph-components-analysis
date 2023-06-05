#include "Graph.h"
#define SQUARE_SIZE 512
void Graph::Component::CUDAFillEccentricities()
{
	vector<Vertex*> *i_members = &(this->members);

	cudaMalloc(&i_members, sizeof(Vertex));

	cudaMemcpy(i_members, this->members, sizeof(Vertex), cudaMemcpyHostToDevice);

	for (int i = 0; i < members.size(); i += SQUARE_SIZE)
	{
		for (int y = i; y < i + SQUARE_SIZE; y++)
		{
			Vertex* vertex = members.at(i);
			vertex->eccentricity = CUDAFindEccentricity <<<1, SQUARE_SIZE >> > (y);
		}



	}
}

__global__ int Graph::Component::CUDAFindEccentricity(int startId)
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
			if (pathDistance.at(neighbourIndex) == -1)
			{
				pathDistance.at(neighbourIndex) = pathDistance.at(current->index) + 1;
				q.push(neighbour);
			}
		}

	}
	return pathDistance.at(current->index);
}



/*

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
	return pathDistance.at(current->index);*/

/*
	for (int i = 0; i < members.size(); i++)
	{
		Vertex* vertex = members.at(i);
		if (vertex->eccentricity == -1)
		{

			vertex->eccentricity = findEccentricity(i);


		}
	}
*/