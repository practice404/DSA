#include<iostream>
#include "Tree.h"
#include<vector>

int main()
{
	Tree<int> tree;
	tree.create_tree();
	Node<int> * root = tree.root;
	tree.preorder(root);
	std::cout<<std::endl;
	tree.iter_preorder();
	std::cout<<std::endl;
	tree.inorder(root);
	std::cout<<std::endl;
	tree.iter_inorder();
	std::cout<<std::endl;
	tree.postorder(root);
	std::cout<<std::endl;
	tree.iter_postorder();
	std::cout<<std::endl;
	tree.levelorder();

}