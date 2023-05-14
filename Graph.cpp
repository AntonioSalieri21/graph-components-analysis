#include "Graph.h"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

void Graph::insertVertex(int id)
{
	this->vertices.push_back(new Vertex(id));
}
void Graph::insertVertex(Vertex* vertex) 
{ 

	this->vertices.push_back(vertex);
	vertex->index = vertices.size() - 1;
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

		Vertex* v_a = searchTree.searchBST(a);
		Vertex* v_b = searchTree.searchBST(b);

		if (v_a == nullptr)
		{
			v_a = searchTree.InsertBST(a);
			insertVertex(v_a);
		}
		if (v_b == nullptr)
		{
			v_b = searchTree.InsertBST(b);
			insertVertex(v_b);
		}
			

		v_b->neighbours.push_back(v_a);
		v_a->neighbours.push_back(v_b);

	}

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

	for (int i = 0; i < res->members.size(); i++)
	{
		res->members.at(i)->index = i;
	}

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

Graph::Vertex* Graph::BST::InsertBST(int data)
{
	if (root == nullptr)
	{
		root = new Vertex(data);
		return root;
	}
	return InsertInnerBST(&root, data);
}

Graph::Vertex* Graph::BST::InsertInnerBST(Vertex** node, int data)
{
	if (*node == nullptr)
	{
		*node = new Vertex(data);
		return *node;
	}
	if (data < (*node)->id)
		return InsertInnerBST(&((*node)->BST_left), data);
	else if (data > (*node)->id)
		return InsertInnerBST(&((*node)->BST_right), data);
	else
		return *node; 
}




Graph::Vertex* Graph::BST::searchBST(int data)
{
	return searchInnerBST(root, data);
}

Graph::Vertex* Graph::BST::searchInnerBST(Vertex* node, int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->id == data)
		return node;

	if (data < node->id)
		return searchInnerBST(node->BST_left, data);

	if (data > node->id)
		return searchInnerBST(node->BST_right, data);
}

void Graph::BST::print()
{
	printInner(root);
}

void Graph::BST::printInner(Vertex* node)
{
	if (node != nullptr)
	{
		cout << node->id << endl;
		printInner(node->BST_left);
		printInner(node->BST_right);
	}
	else return;

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
			/*for (auto vertex : members)
			{
				vertex->eccentricity = findEccentricity(vertex);
				reset();
			}
			break;*/
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
	/*vector<int> path = findPathBFS(startId);

	int max = path.at(0);
	for (auto ecc : path)
	{
		if (ecc > max) max = ecc;
	}
	return max;*/
	return findPathBFS(startId);

}
int Graph::Component::findPathBFS(int startId)
{

	vector<int> pathDistance;//(members.size() + 1, -1);
	pathDistance.assign(members.size() + 1, -1);
	pathDistance.at(startId) = 0;
	queue<Vertex*> q;
	Vertex* start = members.at(startId);
	q.push(start);
	start->color = 1; // устанавливаем цвет стартовой вершины в 1
	Vertex* current = start;
	while (!q.empty())
	{
		current = q.front();
		q.pop();

		//cout << current->id << endl;

		for (auto neighbour : current->neighbours)
			if (neighbour->color != 1) // если соседняя вершина еще не была посещена
			{
				pathDistance.at(neighbour->index) = pathDistance.at(current->index) + 1;
				neighbour->color = 1; // устанавливаем цвет соседней вершины в 1
				q.push(neighbour);
			}
	}
	return pathDistance.at(current->index);

}


void Graph::Component::reset()
{
	for (auto vertex : members)
	{
		vertex->color = 0;
	}
}



void Graph::Component::printEccentricities()
{
	for (auto vertex : members)
		cout << vertex->id << "   " <<  vertex->eccentricity << endl;
}