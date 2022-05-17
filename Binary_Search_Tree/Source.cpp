#include <iostream>
#include <string>
#include "Binary_Search_Tree.h"


int main()
{
	binary_search_tree tree1;

	tree1.root= tree1.insert_leaf(tree1.root, 50);
	tree1.root= tree1.insert_leaf(tree1.root, 60);
	tree1.root= tree1.insert_leaf(tree1.root, 40);
	tree1.root= tree1.insert_leaf(tree1.root, 70);

	tree1.print_tree(tree1.root);
}