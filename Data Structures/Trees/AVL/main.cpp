#include "AVL.h"

int main(int argc, char const *argv[])
{
	AVL tree;
	tree.root = tree.insert(tree.root, 10);
	tree.insert(tree.root, 20);
	tree.insert(tree.root, 15);

	std::cout << tree.root->data;
	return 0;
}