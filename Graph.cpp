#include "Graph.h"
#include <vector>
#include <stack>
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

void Graph::createDirectedEdge(int from, int to)
{
	Vertex* fromVertex = findVertex(from);
	Vertex* toVertex = findVertex(to);

	if (fromVertex != nullptr && toVertex != nullptr)
		fromVertex->neighbours.push_back(toVertex);
}

void Graph::topologicalSort(vector<int>& sortedVertices)
{
	if (!visit(vertices.front(), sortedVertices))
	{
		sortedVertices.clear();
		return;
	}
}

bool Graph::visit(Vertex* vertex, vector<int>& sortedVertices)
{
	if (vertex->color = 2)
		return true;

	if (vertex->color = 1)
	{
		vertex->color = 2;
		return false;
	}
		
	vertex->color = 1;
	for (auto neighbour : vertex->neighbours)
		if (!visit(neighbour, sortedVertices)) return false;

	vertex->color = 2;
	sortedVertices.emplace(sortedVertices.begin(), vertex->id);

	return true;
}

/*
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

void Graph::readGraphFromFile(string path)
{
	string vertex_pair;
	ifstream file(path);

	while (getline(file, vertex_pair)) 
	{
		int a = 0;
		int b = 0;
		getDoubleInt(vertex_pair, a, b);
		Node* first = new Node(a);
		Node* second = new Node(b);

		this->addPair(first, second);
	}

	file.close();

}

*/