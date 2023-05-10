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

		Vertex* BST_left;
		Vertex* BST_right;

		Vertex(int id){this->id = id;}

	};

	class Component {
	public:
		vector<Vertex*> members;
		void print();
	};

	class BST{
	public:
		Vertex* root = nullptr;

		void print();
		void printInner(Vertex* root);

		Vertex* InsertBST(int data);
		Vertex* InsertInnerBST(Vertex* root, int data);

		Vertex* searchBST(int data);
		Vertex* searchInnerBST(Vertex* root, int data);
	};
public:
	vector<Vertex*> vertices;
	vector<Component> components;
	BST searchTree;


	void print();

	void insertVertex(int id);
	void insertVertex(Vertex* vertex);
	void insertVertex(int id, vector<int> neighboursIds);


	Vertex* findVertex(int id);
	void readGraphFromFile(string path);

	Component* getLargestComponent();
	Component defineComponent(Vertex* startVertex);

};

void getDoubleInt(string text, int& a, int& b);

