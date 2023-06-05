#pragma once
#include <vector>
#include <string>
#include <omp.h>
#include <stack>
#include <iostream>
#include <fstream>
#include <queue>
#include <ctime>
#include <unordered_map>
#include <cuda.h>

#define NUM_THREADS 4

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
		int eccentricity = -1;
		int index = -1;

		Vertex* BST_left;
		Vertex* BST_right;

		Vertex(int id){this->id = id;}

		void print()
		{
			for (auto neighbour : neighbours) cout << neighbour->index << endl;
		}

	};

	class Component {
	public:
		vector<Vertex*> members;
		void print();
		int getDiameter();
		int getRadius();
		void printEccentricities();

	private:
		int findEccentricity(int startId);
		int CUDAFindEccentricity(int startId);
		void fillEccentricities();
		void CUDAFillEccentricities();
		void reset();
		int findPathBFS(int startId);
	};

	class BST{
	public:
		Vertex* root;

		void print();
		void printInner(Vertex* node);

		Vertex* InsertBST(int data);
		Vertex* searchBST(int data);
		
	private:
		Vertex* InsertInnerBST(Vertex** node, int data);
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


private:
	Component defineComponent(Vertex* startVertex);

};

void getDoubleInt(string text, int& a, int& b);

