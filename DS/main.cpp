#include <iostream>
#include "LinkedList.cpp"
#include "BinaryTree.cpp"
#include <vector>
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
	
	BinaryTree<int> tree = BinaryTree<int>();
	tree.root = Leaf<int>::CreateLeaf(1);
	tree.root->left = Leaf<int>::CreateLeaf(2);
	tree.root->left->left = Leaf<int>::CreateLeaf(3);
	tree.root->right = Leaf<int>::CreateLeaf(4);
	tree.root->right->left = Leaf<int>::CreateLeaf(5);

	tree.RecInorderTraversal();
	tree.Iterative_Inorder();
	tree.Morris_Traversal();
	
	std::vector<int> in = { 4, 2, 5, 1, 3, 6 };
	std::vector<int> pre = { 1, 2, 4, 5, 3, 6 };
	BinaryTree<int>::Print_PostOrder_Given_Pre_AND_In_Order(pre, in);

	std::cin >> data;
	return 0;
}