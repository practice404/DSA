#include<iostream>
#include "Tree.h"
#include<vector>

int main()
{
	Tree<int> tree;
	tree.create_tree();
	tree.iter_postorder();

	Tree<int> tree2;
	int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    tree2.root = tree.generate_tree_from_traversal(inorder, preorder, 0, 8);
    tree2.iter_preorder();
    tree2.iter_inorder();
    tree2.iter_postorder();
}