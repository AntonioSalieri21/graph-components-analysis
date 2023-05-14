#include "Graph.h"

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