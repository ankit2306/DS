#include <iostream>
#include "LinkedList.cpp"
#include "BinaryTree.cpp"
using namespace std;

int main()
{
	char data = '0';
	LinkedList<int> newList = LinkedList<int>();
	newList.AppendElementInLList(2)->AppendElementInLList(3);
	newList.printLList();
	newList.DeleteElementInLList(1);
	newList.printLList();
	newList.PrependElementInLList(13);
	newList.printLList();
	newList.DeleteElementInLList(3);
	newList.printLList();
	newList.DeleteLList();
	newList.printLList();
	
	BninaryTree<int> tree = BninaryTree<int>();
	tree.root = Leaf<int>::CreateLeaf(1);
	tree.root->left = Leaf<int>::CreateLeaf(2);
	tree.root->left->left = Leaf<int>::CreateLeaf(3);
	tree.root->right = Leaf<int>::CreateLeaf(4);
	tree.root->right->left = Leaf<int>::CreateLeaf(5);

	tree.RecInorderTraversal();
	tree.Iterative_Inorder();
	
	std::cin >> data;
	return 0;
}