#include "BST.h"
#include<vector>

int main()
{
	BST tree;
	std::vector<int> v {10,5,20,8,30};
	// std::vector<int> v {10};
	for(auto i : v)
		tree.insert(i);

	tree.inorder();
	tree.preorder();
	tree.remove(tree.root, 10);
	tree.inorder();

	std::vector<int> pre {30,20,10,15,25,40,50,45};
	BST tree2;
	tree2.create_from_preorder(pre);
	tree2.preorder();
	// std::cout << tree.height(tree.root->lchild) << " " << tree.height(tree.root->lchild) << std::endl;
	// std::cout << tree.in_pedecessor(tree.root->lchild)->data<<std::endl;
	// std::cout << tree.in_successor(tree.root->rchild)->data;
}