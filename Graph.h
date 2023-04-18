#pragma once
#include <vector>
using namespace std;
class Graph 
{

public:

	class Vertex
	{

	public:
		int id;	
		vector<Vertex*> neighbours;
		int color;

		Vertex(int id){this->id = id;}

	};

	vector<Vertex*> vertices;


	void insertVertex(int id);
	void insertVertex(int id, vector<int> neighboursIds);

	Vertex* findVertex(int id);

	void createDirectedEdge(int from, int to);
	void topologicalSort(vector<int>& sortedVertices);
	bool visit(Vertex* vertex, vector<int>& sortedVertices);
	bool findIdDFS(int id);
};

