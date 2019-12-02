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

	std::cout << "RecInorderTraversal: " << std::endl;
	tree.RecInorderTraversal();

	std::cout << "Iterative_Inorder: " << std::endl;
	tree.Iterative_Inorder();

	std::cout << "Morris_Traversal: " << std::endl;
	tree.Morris_Traversal();
	
	std::vector<int> in = { 4, 2, 5, 1, 3, 6 };
	std::vector<int> pre = { 1, 2, 4, 5, 3, 6 };

	std::cout << "Print_PostOrder_Given_Pre_AND_In_Order: " << std::endl;
	BinaryTree<int>::Print_PostOrder_Given_Pre_AND_In_Order(pre, in);

	/*std::vector<Leaf<int>*> trees = BinaryTree<int>::Trees_Given_Inorder(in, 0, in.size() - 1);
	std::cout << "Trees_Given_Inorder: " << std::endl;
	for (const Leaf<int> *leaf : trees)
	{
		BinaryTree<int>::Print_Pre_From_Root(leaf);
		std::cout << std::endl;
	}*/

	tree.Construct_Tree_Sum_Of_Inoder_Successors_And_Predecessors();
	std::cout << "Construct_Tree_Sum_Of_Inoder_Successors_And_Predecessors: " << std::endl;
	tree.RecInorderTraversal();

	Leaf<int>* successor = tree.Inorder_Successor_OF_Node_In_BT(tree.root);
	std::cout << "Inorder_Successor_OF_Node_In_BT: ";
	if (successor)
		std::cout << successor->data;
	cout << std::endl;

	std::cout << "Print_Nth_Inorder_Node: ";
	tree.Print_Nth_Inorder_Node(3);

	std::cout << "Print_Nth_Postorder_Node: ";
	tree.Print_Nth_Postorder_Node(1);

	std::cout << "Print_Level_Order_Rec" << std::endl;
	tree.Print_Level_Order_Rec();
	
	std::cout << "Print_Level_Order_Itr" << std::endl;
	tree.Print_Level_Order_Itr();

	std::cout << "Print_Spiral_Order_Itr" << std::endl;
	tree.Print_Spiral_Order_Itr();

	std::cin >> data;
	return 0;
}
