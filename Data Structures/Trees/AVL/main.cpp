#include "AVL.h"
using namespace std;
int main(int argc, char const *argv[])
{
	AVL tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.insert(tree.root, A[i]);
    }
 
    tree.inorder(); // 5 10 20 25 27 28 30 
    cout << endl;
 
    tree.remove(tree.root, 28);
   
    tree.inorder(); // 5 10 20 25 27 30 

    cout << endl;
 
    return 0;
}