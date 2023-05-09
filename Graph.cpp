#include "Graph.h"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

void Graph::insertVertex(int id) {this->vertices.push_back(new Vertex(id));}
void Graph::insertVertex(int id, vector<int> neighboursIds)
{
	Vertex* newVertex = new Vertex(id);

	for (auto neighbourId : neighboursIds)
	{
		Vertex* neighbour = findVertex(neighbourId);

		if (neighbour != nullptr)
		{
			/*neighbour->neighbours.push_back(newVertex);
			if(neighbour->id != newVertex->id)*/
			newVertex->neighbours.push_back(neighbour);
		}
	}
	
	this->vertices.push_back(newVertex);
}

Graph::Vertex* Graph::findVertex(int id)
{
	for (auto vertex : this->vertices)
	{
		if (vertex->id == id)
			return vertex;
	}
	return nullptr;
}



bool Graph::findIdDFS(int id)
{
	Vertex* current = vertices.front();
	stack<Vertex*> stack;

	stack.push(current);
	current->color = 1;

	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();

		current->color = 2;

		if (current->id == id)
			return true;

		for (auto neighbour : current->neighbours)
		{
			if (neighbour->color == 0)
			{
				stack.push(neighbour);
				neighbour->color = 1;
			}
		}
	}
}

void getDoubleInt(string text, int& a, int& b)
{

	int x = 0;
	string* tmp = new string[text.length()];
	while (text[x] != ' ')
	{
		tmp->push_back(text.at(x));
		x++;
	}
	a = stoi(*tmp);

	x++;

	tmp = new string[text.length()];
	while (text[x] != '\0')
	{
		tmp->push_back(text.at(x));
		x++;
	}
	b = stoi(*tmp);

	return;

}

Graph::Vertex* Graph::searchCreateVertex(int id)
{

	return nullptr;
}
void Graph::readGraphFromFile(string path)
{
	string vertex_pair;
	ifstream file(path);

	int searchCount = 0;
	int addCount = 0;
	while (getline(file, vertex_pair))
	{
		int a = 0;
		int b = 0;
		getDoubleInt(vertex_pair, a, b);

		


		Vertex* v_a = findVertex(a);
		Vertex* v_b = findVertex(b);

		if (v_a == nullptr)
		{
			insertVertex(a);
			v_a = findVertex(a);
		}

		if (v_b == nullptr)
		{
			insertVertex(b);
			v_b = findVertex(b);
		}

		//cout << v_a->id << "   " << v_b->id << endl;
		//Vertex* v_a = searchCreateVertex(a);
		//Vertex* v_b = searchCreateVertex(b);

		v_b->neighbours.push_back(v_a);
		v_a->neighbours.push_back(v_b);

	}

	cout << "Number of adding vertex: " << addCount << endl;
	cout << "Number of searching vertex: " << searchCount << endl;

	file.close();

}

Graph::Component* Graph::getLargestComponent()
{

	for (auto vertex : vertices)
	{
		if (vertex->color == 0)
			components.push_back(defineComponent(vertex));
	}

	Component* res = &components.at(0);

	for(auto component : components)
		if (component.members.size() > res->members.size()) { res = &component; }

	return res;
}

Graph::Component Graph::defineComponent(Vertex* startVertex)
{
	Component comp;

	Vertex* current = startVertex;
	stack<Vertex*> stack;

	stack.push(current);
	current->color = 1;

	while (!stack.empty())
	{
		current = stack.top();
		comp.members.push_back(current);
		stack.pop();

		//cout << current->id << endl;

		current->color = 2;

		for (auto neighbour : current->neighbours)
		{
			if (neighbour->color == 0)
			{
				stack.push(neighbour);
				neighbour->color = 1;
			}
		}
	}


	return comp;
}

void Graph::print()
{
	for (auto vertex : vertices)
	{
		cout << vertex->id;
		for (auto neighbour : vertex->neighbours)
			cout << "   " << neighbour->id;

		cout << endl;
	}

}

void Graph::Component::print()
{
	for(auto member : members)
	{
		cout << member->id;
		for (auto neighbour : member->neighbours)
			cout << "   " << neighbour->id;

		cout << endl;
	}
}


