/*
 * main.cpp
 *
 *  Created on: Jul 21, 2014
 *      Author: Hvarnah
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>

using namespace std; 
unsigned int size = 500000;

struct node {node * next_node;int num;};

void very_Bad_Function(vector<node> & useless_list)
{
	int bad_node_num = rand()%size;
	int another_node_num = rand()%size;
	if (bad_node_num < another_node_num)
		swap(bad_node_num, another_node_num);

	useless_list[bad_node_num].next_node = &useless_list[another_node_num];
}

void find_Cycle(vector<node> & useless_list)
{
	node * fast_iterator;
	node * slow_iterator;
	fast_iterator = &*useless_list.begin();
	slow_iterator = &*useless_list.begin();
	int i = 0;

	while (fast_iterator->next_node != NULL)
	{
		if (fast_iterator->next_node == slow_iterator)
		{
			cout << "cycle found\n";
			return;
		}

		fast_iterator = fast_iterator->next_node;
		if (i % 2 == 1) 
			slow_iterator = slow_iterator->next_node;
		i++;
	}
	cout << "cycle not found\n";
}

int main(int argc, char *argv[])
{
	vector<node> useless_list;

	useless_list.resize(size);
	
	for (int i = 0; i < size - 1; ++i)
	{
		useless_list[i].next_node = &useless_list[i+1];
		useless_list[i].num = i;
	}

	useless_list.back().next_node = NULL;
	useless_list.back().num = size - 1;
	very_Bad_Function(useless_list);

	find_Cycle(useless_list);

	system("PAUSE");
}