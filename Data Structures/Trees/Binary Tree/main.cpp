#include<iostream>
#include "Tree.h"
#include<vector>

int main()
{
	Tree<int> tree;
	// tree.create_tree();
	// Node<int> * root = tree.root;
	// tree.preorder(root);
	// std::cout<<std::endl;
	// tree.iter_preorder();
	// std::cout<<std::endl;
	// tree.inorder(root);
	// std::cout<<std::endl;
	// tree.iter_inorder();
	// std::cout<<std::endl;
	// tree.postorder(root);
	// std::cout<<std::endl;
	// tree.iter_postorder();
	// std::cout<<std::endl;
	// tree.levelorder();

	int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    tree.root = tree.generate_tree_from_traversal(inorder, preorder, 0, 8);
    tree.iter_preorder();
    std::cout<<std::endl;
    tree.iter_inorder();
}