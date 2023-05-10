#include "Graph.h"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

void Graph::insertVertex(int id) {this->vertices.push_back(new Vertex(id));}
void Graph::insertVertex(Vertex* vertex) { this->vertices.push_back(vertex); }
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
			vertices.push_back(v_a);
		}
		if (v_b == nullptr)
		{
			v_b = searchTree.InsertBST(b);
			vertices.push_back(v_b);
		}

		v_b->neighbours.push_back(v_a);
		v_a->neighbours.push_back(v_b);


		//cout << searchTree.searchBST(a) << endl;


		cout << v_a->id << "   " << v_b->id << endl;

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
	else
		return InsertInnerBST(root, data);
}

Graph::Vertex* Graph::BST::InsertInnerBST(Vertex* root, int data)
{
	if (root == nullptr)
		return new Vertex(data);
	if (data < root->id)
		root->BST_left = InsertInnerBST(root->BST_left, data);
	if (data > root->id)
		root->BST_right = InsertInnerBST(root->BST_right, data);

	return root;
}

Graph::Vertex* Graph::BST::searchBST(int data)
{
	return searchInnerBST(root, data);
}

Graph::Vertex* Graph::BST::searchInnerBST(Vertex* root, int data)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->id == data)
		return root;

	if (data < root->id)
		return searchInnerBST(root->BST_left, data);

	if (data > root->id)
		return searchInnerBST(root->BST_right, data);
}

void Graph::BST::print()
{
	printInner(root);
}

void Graph::BST::printInner(Vertex* root)
{
	if (root != nullptr)
	{
		cout << root->id << endl;
		printInner(root->BST_left);
		printInner(root->BST_right);
	}
	else return;

}