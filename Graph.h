#pragma once
#include <vector>
#include <string>
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

	class Component {
	public:
		vector<Vertex*> members;
		void print();
	};

	vector<Vertex*> vertices;
	vector<Component> components;

	void print();

	void insertVertex(int id);
	Vertex* insertVertexAdress(int id);
	void insertVertex(int id, vector<int> neighboursIds);
	void QuickSort(int left, int right);
	void swap(Vertex* src, Vertex* dst);

	Vertex* findVertex(int id);
	Vertex* searchCreateVertex(int id);
	bool findIdDFS(int id);
	void readGraphFromFile(string path);

	Component* getLargestComponent();
	Component defineComponent(Vertex* startVertex);

};

void getDoubleInt(string text, int& a, int& b);

