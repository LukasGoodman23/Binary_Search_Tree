#include "Binary_Search_Tree.h"

leaf *binary_search_tree::insert_leaf(leaf *place_leaf, int input)
{
	if (place_leaf == nullptr)
	{
		place_leaf= new leaf;
		place_leaf->data= input;
		place_leaf->big_leaf= nullptr;
		place_leaf->small_leaf= nullptr;
		number_of_leaves++;
	}
	else if (place_leaf->data > input)
	{
		place_leaf->small_leaf= insert_leaf(place_leaf->small_leaf, input);
	}
	else
	{
		place_leaf->big_leaf= insert_leaf(place_leaf->big_leaf, input);
	}
	return place_leaf;
}

void binary_search_tree::print_tree(leaf *place_leaf)
{
	if (place_leaf->small_leaf != nullptr)
	{
		print_tree(place_leaf->small_leaf);
	}

	std::cout << place_leaf->data << "\n";

	if (place_leaf->big_leaf != nullptr)
	{
		print_tree(place_leaf->big_leaf);
	}

}

int binary_search_tree::get_maximum_value()
{
	leaf *temp_leaf= root;

	while (temp_leaf->big_leaf != nullptr)
	{
		temp_leaf= temp_leaf->big_leaf;
	}

	return temp_leaf->data;
}

int binary_search_tree::get_minimum_value()
{
	leaf *temp_leaf= root;

	while (temp_leaf->small_leaf != nullptr)
	{
		temp_leaf= temp_leaf->small_leaf;
	}

	return temp_leaf->data;
}

bool binary_search_tree::does_leaf_exist(int key)
{
	leaf *temp_leaf= root;
	bool return_bool= false;
	while (temp_leaf != nullptr)
	{
		if (key == temp_leaf->data) { return true; }
		else
		{
			if (key > temp_leaf->data && temp_leaf->big_leaf != nullptr) { temp_leaf= temp_leaf->big_leaf; }
			else
			{
				temp_leaf= temp_leaf->small_leaf;
			}
		}
	}
	return return_bool;
}

void binary_search_tree::delete_leaf(int input)
{
	leaf *temp_leaf= root;
	if (does_leaf_exist(input))
	{
		while (temp_leaf->data != input)
		{
			if (input > temp_leaf->data && temp_leaf->big_leaf != nullptr) { temp_leaf= temp_leaf->big_leaf; }
			else
			{
				temp_leaf= temp_leaf->small_leaf;
			}
		}
		while (temp_leaf != nullptr)
		{
			if (temp_leaf->big_leaf != nullptr)
			{
				temp_leaf->data= temp_leaf->big_leaf->data;
			}
			else if (temp_leaf->small_leaf != nullptr)
			{
				temp_leaf->data= temp_leaf->small_leaf->data;
			}
			else
			{
				temp_leaf= nullptr;
			}
		}
	}
}