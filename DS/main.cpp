#include <iostream>
#include "LinkedList.cpp"
#include "BinaryTree.cpp"
#include <vector>
#include "DynamicProgramming.cpp"
using namespace std;

int main()
{
	char data = '0';
	//LinkedList<int> newList = LinkedList<int>();
	//newList.AppendElementInLList(2)->AppendElementInLList(3);
	//newList.printLList();
	//newList.DeleteElementInLList(1);
	//newList.printLList();
	//newList.PrependElementInLList(13);
	//newList.printLList();
	//newList.DeleteElementInLList(3);
	//newList.printLList();
	//newList.DeleteLList();
	//newList.printLList();
	//
	//BinaryTree<int> tree = BinaryTree<int>();
	//tree.root = Leaf<int>::CreateLeaf(1);
	//tree.root->left = Leaf<int>::CreateLeaf(2);
	//tree.root->left->left = Leaf<int>::CreateLeaf(3);
	//tree.root->right = Leaf<int>::CreateLeaf(4);
	//tree.root->right->left = Leaf<int>::CreateLeaf(5);

	//std::cout << "RecInorderTraversal: " << std::endl;
	//tree.RecInorderTraversal();

	//std::cout << "Iterative_Inorder: " << std::endl;
	//tree.Iterative_Inorder();

	//std::cout << "Morris_Traversal: " << std::endl;
	//tree.Morris_Traversal();
	//
	//std::vector<int> in = { 4, 2, 5, 1, 3, 6 };
	//std::vector<int> pre = { 1, 2, 4, 5, 3, 6 };

	//std::cout << "Print_PostOrder_Given_Pre_AND_In_Order: " << std::endl;
	//BinaryTree<int>::Print_PostOrder_Given_Pre_AND_In_Order(pre, in);

	///*std::vector<Leaf<int>*> trees = BinaryTree<int>::Trees_Given_Inorder(in, 0, in.size() - 1);
	//std::cout << "Trees_Given_Inorder: " << std::endl;
	//for (const Leaf<int> *leaf : trees)
	//{
	//	BinaryTree<int>::Print_Pre_From_Root(leaf);
	//	std::cout << std::endl;
	//}*/

	//tree.Construct_Tree_Sum_Of_Inoder_Successors_And_Predecessors();
	//std::cout << "Construct_Tree_Sum_Of_Inoder_Successors_And_Predecessors: " << std::endl;
	//tree.RecInorderTraversal();

	//Leaf<int>* successor = tree.Inorder_Successor_OF_Node_In_BT(tree.root);
	//std::cout << "Inorder_Successor_OF_Node_In_BT: ";
	//if (successor)
	//	std::cout << successor->data;
	//cout << std::endl;

	//std::cout << "Print_Nth_Inorder_Node: ";
	//tree.Print_Nth_Inorder_Node(3);

	//std::cout << "Print_Nth_Postorder_Node: ";
	//tree.Print_Nth_Postorder_Node(1);

	//std::cout << "Print_Level_Order_Rec" << std::endl;
	//tree.Print_Level_Order_Rec();
	//
	//std::cout << "Print_Level_Order_Itr" << std::endl;
	//tree.Print_Level_Order_Itr();

	//std::cout << "Print_Level_Order_Linewise_Itr" << std::endl;
	//tree.Print_Level_Order_Linewise_Itr();

	//std::cout << "Print_Spiral_Order_Itr" << std::endl;
	//tree.Print_Spiral_Order_Itr();

	//std::cout << "Reverse_Path" << std::endl;
	//tree.Reverse_Path(2);
	//tree.Print_Level_Order_Linewise_Itr();

	std::cout << "Nth Ugly number: " << std::endl;
	std::cout << DynamicProgramming::UglyNumbers(150) << std::endl;

	std::cout << "Fib_Using_Matrix_Expansion : " << std::endl;
	std::cout << DynamicProgramming::Fib_Using_Matrix_Expansion(12) << std::endl;

	std::cout << "Catlan Number : " << std::endl;
	std::cout << DynamicProgramming::Catlan(9) << std::endl;

	std::cout << "Binomial Coefficient : " << std::endl;
	std::cout << DynamicProgramming::Binomial_Coeff(4, 2) << std::endl;

	int gold[MAX][MAX] = { {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << "Get Max Gold :" << DynamicProgramming::Get_Max_Gold(gold, m, n) << std::endl;

	int S[] = { 1,2,3 };
	std::cout << "Coin Change: " << DynamicProgramming::Coin_Change(S, 3, 3) << std::endl;

	std::cout << "Subset Sum: " << std::endl;
	std::cout << DynamicProgramming::Subset_Sum(S, 3, 5) << std::endl;

	int Set[] = { 12, 4, 6, 18, 24, 36 };
	std::cout << "Largest_Divisible_Pair: " << DynamicProgramming::Largest_Divisible_Pair(Set, sizeof(Set)/sizeof(int)) << std::endl;

	int arr[] = {1, 2, 3, 4, 5}; 
	std::cout << "Print_All_Subsets_With_Given_Sum: ";
	DynamicProgramming::Print_All_Subsets_With_Given_Sum(arr, sizeof(arr) / sizeof(int), 10);

	std::cout << "Compute nCr % p: ";
	std::cout << DynamicProgramming::nCrModP(10, 2, 13) << std::endl;

	int rods[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	std::cout << "Cut_Rod: " << DynamicProgramming::Cut_Rod(rods, sizeof(rods) / sizeof(int)) << std::endl;

	int** mat = new int* [4] {
		new int[4] {9, 6, 5, 2},
		new int[4] {8, 7, 6, 5},
		new int[4] {7, 3, 1, 6},
		new int[4] {1, 1, 1, 7},
	};
	std::vector<int> path;
	DynamicProgramming::Longest_Snake_Sequence(mat, 4, 4, path);
	for(int p : path)
		std:: cout << p << ' ';
	std::cout << std::endl;
	std::cout << "Special Sequence: " << DynamicProgramming::Get_Special_Sequence(9, 4) << std::endl;
	const char str1[] = "ABCDGH";
	const char str2[] = "AEDFHR";
	std::cout << "Longest Common Subsequence: " << DynamicProgramming::Longest_Common_Subsequence(str1, str2, sizeof(str1) / sizeof(char) - 1, sizeof(str2) / sizeof(char) - 1) << std::endl;

	int arrLIS[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	std::cout << "Longest Increasing Subsequence: " << DynamicProgramming::Longest_Increasing_Subsequence(arrLIS, sizeof(arrLIS) / sizeof(arrLIS[0])) << std::endl;

	int arrBS[] = { 1, 15, 51, 45, 33, 100, 12, 18, 9 };  
	std::cout << "Longest Bitonic Sequence: " << DynamicProgramming::Longest_Bitonic_Sequence(arrBS, sizeof(arrBS) / sizeof(arrBS[0]));
	std::vector<int> set = {1, 2, 3, 4};
	std::cout << "Product Subsequence: " << DynamicProgramming::Product_Subsequence(set, 10) << std::endl;

	int arr_max_Wo_3_consec[] = { 2,0,4,1,5 };
	std::cout << "Max sum subseq. without three consecutive elemets in an array: " << DynamicProgramming::Max_Sum_Wo_3_Consec(arr_max_Wo_3_consec, sizeof(arr_max_Wo_3_consec) / sizeof(arr_max_Wo_3_consec[0])) << std::endl;

	int arr_abs_diff_1[] = { 2,0,4,1,5 };
	std::cout << "Longest Subseq. with abs-diff 1: " << DynamicProgramming::Longest_Subsequence_With_Diff_1(arr_abs_diff_1, sizeof(arr_abs_diff_1) / sizeof(arr_abs_diff_1[0])) << std::endl;

	std::vector<pair<int, int>> pairs = { std::make_pair(5, 24), {15, 25}, {27, 40}, {50, 60} };
	std::cout << "Length of chain of pairs: " << DynamicProgramming::Longest_Chain_Pair(pairs) << std::endl;

	std::vector<int> arr_max_pair = { 3, 5, 10, 15, 17, 12, 9 };
	std:cout << "max sum of pairs: " << DynamicProgramming::Maximum_Sum_Of_Pairs_With_Diff_K(arr_max_pair, 4) << std::endl;
	std::cin >> data;
	std::cout << std::endl;
	return 0;
}
