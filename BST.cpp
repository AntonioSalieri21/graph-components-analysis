#include "Graph.h"

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