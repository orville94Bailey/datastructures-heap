#include "stdafx.h"
#include "heap.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

heap::heap()
{
	max_heap = false;
	min_heap = false;
	has_added = false;
	current_pos = 0;
}


heap::~heap()
{
	cin.get();
}

bool heap::is_max_heap()
{
	return max_heap;
}

bool heap::is_min_heap()
{
	return min_heap;
}

void heap::set_max_heap()
{
	if (min_heap == false)
	{
		max_heap = true;
		for (int i = 0; i < HEAPSIZE;i++)
		{
			the_array[i] = 0x11111111;
		}
	}
	else
	{
		cout << "The heap is locked in min heap mode"<<endl;
	}
}

void heap::set_min_heap()
{
	if (max_heap == false)
	{
		min_heap = true;
		for (int i = 0; i < HEAPSIZE; i++)
		{
			the_array[i] = 0x11111111;
		}
	}
	else
	{
		cout << "The heap is locked in max heap mode" << endl;
	}
}

void heap::insert(int data)
{
	if (has_added)
	{
		if (min_heap)
		{
			if (current_pos < HEAPSIZE)
			{
				the_array[current_pos] = data;
				current_pos++;

				for (int i = current_pos; i > -1;i = (i - 1) / 2)
				{
					cout << "stuck in min heap insert" << endl;
					if (the_array[i] < the_array[parent_index(i)])
					{
						swap(i, parent_index(i));
					}
					else
					{
						break;
					}
				}
			}
		}
		else if (max_heap)
		{
			if (current_pos < HEAPSIZE)
			{
				the_array[current_pos] = data;
				current_pos++;

				for (int i = current_pos; i > -1;i = (i - 1) / 2)
				{
					cout << "stuck in max heap insert" << endl;
					if (the_array[i] > the_array[parent_index(i)])
					{
						swap(i, parent_index(i));
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			cout << "You have not set a heap type.  Please set heap type before inserting." << endl;
		}
	}
	else
	{
		the_array[current_pos] = data;
		has_added = true;
	}
	
}

void heap::print()
{
	for (int i = 0; i < current_pos;i++)
	{
		cout << the_array[i] << ", ";
	}
}

int heap::parent_index(int child_index)
{
	return (child_index -1) /2;
}

int heap::left_child_index(int parent_index)
{
	return parent_index*2 + 1;
}

int heap::right_child_index(int parent_index)
{
	return parent_index*2 + 2;
}

void heap::swap(int index_1, int index_2)
{
	int holder;
	holder = the_array[index_1];
	cout << "Swapped " << the_array[index_1] << " and " << the_array[index_2] << endl;
	the_array[index_1] = the_array[index_2];
	the_array[index_2] = holder;


	 
}
