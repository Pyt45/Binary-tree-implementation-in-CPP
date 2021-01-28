#include "Tree.class.hpp"

int main(){

	Btree *tree = new Btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	tree->printBtree();
	/*tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();*/

	delete tree;

}