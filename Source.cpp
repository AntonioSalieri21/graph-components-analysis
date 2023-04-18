#include <iostream>
#include "Graph.h"
using namespace std;


int main()
{
	Graph g;
	/*
	g.insertVertex(1);

	vector<int> neighbourIds;
	neighbourIds.push_back(1);

	g.insertVertex(2, neighbourIds);

	neighbourIds.clear();
	neighbourIds.push_back(1);
	neighbourIds.push_back(2);

	g.insertVertex(3, neighbourIds);

	neighbourIds.clear();
	neighbourIds.push_back(3);

	g.insertVertex(4, neighbourIds);
	g.insertVertex(5, neighbourIds);

	g.insertVertex(6);
	g.insertVertex(7);

	neighbourIds.clear();
	neighbourIds.push_back(3);
	neighbourIds.push_back(6);
	neighbourIds.push_back(7);

	g.insertVertex(8, neighbourIds);
	neighbourIds.clear();
	neighbourIds.push_back(2);
	neighbourIds.push_back(8);

	g.insertVertex(9, neighbourIds);

	neighbourIds.clear();
	neighbourIds.push_back(9);

	g.insertVertex(10, neighbourIds);

	//cout << "Vertex: " << (g.findIdDFS(0) ? "" : "NOT ") << "found" << endl;
	*/

	g.insertVertex(1);
	g.insertVertex(2);
	g.insertVertex(3);
	g.insertVertex(4);
	g.insertVertex(5);
	g.insertVertex(6);
	g.insertVertex(7);
	g.insertVertex(8);
	g.insertVertex(9);
	g.insertVertex(10);

	g.createDirectedEdge(1, 2);
	g.createDirectedEdge(1, 3);
	g.createDirectedEdge(3, 4);
	g.createDirectedEdge(3, 5);
	g.createDirectedEdge(3, 8);
	g.createDirectedEdge(8, 6);
	g.createDirectedEdge(8, 7);
	g.createDirectedEdge(8, 9);
	g.createDirectedEdge(9, 10);
	g.createDirectedEdge(2, 3);
	g.createDirectedEdge(2, 9);

	//cout << "Vertex: " << (g.findIdDFS(7) ? "" : "NOT ") << "found" << endl;
	vector<int> sortedVertices;
	g.topologicalSort(sortedVertices);

	for (auto sortedVertex : sortedVertices)
		cout << sortedVertex << endl;



	return 0;
}