#pragma once
#define HEAPSIZE 1000

class heap
{
public:
	heap();
	~heap();
	bool is_max_heap(),
		 is_min_heap();
	void set_max_heap(),
		 set_min_heap();
	void insert(int data);
	void print();

	int parent_index(int child_index);
	int left_child_index(int parent_index);
	int right_child_index(int parent_index);
private:
	int the_array[HEAPSIZE];
	int current_pos;
	
	void swap(int index_1, int index_2);
	bool max_heap,
		 min_heap,
		 has_added;

};

