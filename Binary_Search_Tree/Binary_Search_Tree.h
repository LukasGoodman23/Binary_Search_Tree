#pragma once

#include <iostream>
#include <string>
#include <assert.h>

struct leaf
{
	int data;

	leaf *big_leaf= nullptr;
	leaf *small_leaf= nullptr;
};

class binary_search_tree
{
private:
	int number_of_leaves= 0;

public:
	leaf *root= nullptr;
	leaf *get_root() { return root; }
	int get_size() { return number_of_leaves; }

	leaf *insert_leaf(leaf *place_leaf, int input);
	bool does_leaf_exist(int input);
	void print_tree(leaf *place_leaf);
	int get_minimum_value();
	int get_maximum_value();
	void delete_leaf(int input);
};