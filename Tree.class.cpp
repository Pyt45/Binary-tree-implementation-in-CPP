#include "Tree.class.hpp"

Btree::Btree(): root(NULL) {}

Btree::~Btree() { destroy_tree(); }

void	Btree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new t_node;
		root->key = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void	Btree::insert(int key, t_node *leaf)
{
	if (key < leaf->key)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new t_node;
			leaf->left->key = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->key)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new t_node;
			leaf->right->key = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

t_node		*Btree::search(int key)
{
	return search(key, root);
}

t_node		*Btree::search(int key, t_node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key)
			return leaf;
		else if (key < leaf->key)
			return search(key, leaf->left);
		else if (key >= leaf->key)
			return search(key, leaf->right);
	}
	return NULL;
}

void	Btree::destroy_tree(t_node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete	leaf;
	}
}

void	Btree::destroy_tree()
{
	destroy_tree(root);
}

void 	Btree::inorder_print(){
	inorder_print(root);
	std::cout << "\n";
}

void	Btree::inorder_print(t_node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		std::cout << leaf->key << ",";
		inorder_print(leaf->right);
	}
}

void 	Btree::postorder_print(){
	postorder_print(root);
	std::cout << "\n";
}

void 	Btree::postorder_print(t_node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		std::cout << leaf->key << ",";
	}
}

void 	Btree::preorder_print(){
	preorder_print(root);
	std::cout << "\n";
}

void 	Btree::preorder_print(t_node *leaf){
	if(leaf != NULL){
		std::cout << leaf->key << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

void	Btree::printBtree()
{
	printBtree(root, 0);
}

void	Btree::printBtree(t_node *leaf, int space)
{
	if (leaf != NULL)
	{
		space += count;
		printBtree(leaf->right, space);
		std::cout << std::endl;
		for (int i = count; i < space; i++)
			std::cout << " ";
		std::cout << leaf->key << std::endl;
		printBtree(leaf->left, space);
	}
}