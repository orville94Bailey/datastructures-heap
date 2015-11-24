// my_heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "heap.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	heap h;

	h.set_min_heap();
	
	h.insert(1);
	h.insert(3);
	h.insert(2);
	h.insert(6);
	h.insert(7);
	h.insert(4);

	h.print();
    return 0;
}

