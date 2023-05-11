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
		Vertex* root;

		void print();
		void printInner(Vertex* node);

		Vertex* InsertBST(int data);
		Vertex* InsertInnerBST(Vertex** node, int data);

		Vertex* searchBST(int data);
		Vertex* searchInnerBST(Vertex* node, int data);
	};
public:
	vector<Vertex*> vertices;
	vector<Component> components;
	BST searchTree;


	void print();

	void insertVertex(int id);
	void insertVertex(Vertex* vertex);

	void readGraphFromFile(string path);

	Component* getLargestComponent();
	Component defineComponent(Vertex* startVertex);

};

void getDoubleInt(string text, int& a, int& b);

