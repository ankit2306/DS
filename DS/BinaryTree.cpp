#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include "Leaf.cpp"
#include "Stack.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class BinaryTree
{
private:

	static void Print_PostOrder_Given_Pre_AND_In_Order_Util(class std::vector<T>::const_iterator pre, class std::vector<T>::const_iterator in, int size)
	{
		class std::vector<T>::const_iterator index_it = std::find(in, in + size - 1, *pre);
		int index = distance(in, index_it);

		if (index != 0)
			Print_PostOrder_Given_Pre_AND_In_Order_Util(pre + 1, in, index);
		if (index != size - 1)
			Print_PostOrder_Given_Pre_AND_In_Order_Util(pre + index + 1, in + index + 1, size - index - 1);

		std::cout << *index_it << " ";
	}

	void Inorder_Util(std::vector<T>& in, Leaf<T>* root)
	{
		if (root == nullptr)
			return;
		Inorder_Util(in, root->left);
		in.push_back(root->data);
		Inorder_Util(in, root->right);
	}

	void Inorder_Util(std::vector<T>& in, Leaf<T>* root, int *index)
	{
		if (root == nullptr)
			return;
		Inorder_Util(in, root->left, index);
		root->data = in[*index - 1] + in[*index + 1];
		++*index;
		Inorder_Util(in, root->right, index);
	}

	static Leaf<T>* Rec_Search_Element(const Leaf<T>* location, Stack<Leaf<T>* >& stack , Leaf<T>* root)
	{
		if (root == nullptr)
			return nullptr;

		if (root == location)
			return root;

		stack.Push(root);

		if(Rec_Search_Element(location, stack, root->left) == nullptr)
			stack.Pop();

		if(Rec_Search_Element(location, stack, root->right) == nullptr)
			stack.Pop();
	}

	static void Print_Nth_Inorder_Node_Util(Leaf<T>* root, int n)
	{
		static int count = 0;

		if (!root)
			return;

		if (count <= n)
		{
			Print_Nth_Inorder_Node_Util(root->left, n);
			count++;

			if (count == n)
			{
				std::cout << root->data << std::endl;
			}
			Print_Nth_Inorder_Node_Util(root->right, n);
		}
	}

	static void Print_Nth_Postorder_Node_Util(Leaf<T>* root, int n)
	{
		static int count = 0;

		if (!root)
			return;

		if(count <= n)
		{
			Print_Nth_Postorder_Node_Util(root->left, n);

			Print_Nth_Postorder_Node_Util(root->right, n);

			count++;

			if (count == n)
			{
				std::cout << root->data << std::endl;
			}
		}
	}

	static void Print_Given_Level_Util(Leaf<T>* root, int level)
	{
		if (!root)
			return;

		if (level == 1)
		{
			std::cout << root->data << std::endl;
		}
		else if (level > 1)
		{
			Print_Given_Level_Util(root->left, level - 1);
			Print_Given_Level_Util(root->right, level - 1);
		}
	}


public:

	Leaf<T>* root;

	void RecInorderTraversal()
	{
		if (root)
		{
			Rec_Inorder(root);
			std::cout << std::endl;
		}
	}

	void Rec_Inorder(Leaf<T> *leaf)
	{
		if (leaf == nullptr)
			return;
		Rec_Inorder(leaf->left);
		std::cout << leaf->data << " ";
		Rec_Inorder(leaf->right);
	}

	void Iterative_Inorder() const
	{
		Stack<Leaf<T>*> stack = Stack<Leaf<T>*>();
		Leaf<T>* current = this->root;

		while (current || !stack.IsEmpty())
		{
			while (current)
			{
				stack.Push(current);
				current = current->left;
			}

			Leaf<T>* poppedData = stack.Pop();
			std::cout << poppedData->data << " ";
			current = poppedData->right;
		}
		std::cout << std::endl;
	}

	void Morris_Traversal()
	{
		if (!this->root)
			return;

		Leaf<T> *current, *pre;
		current = this->root;

		while (current)
		{
			if (current->left == nullptr)
			{
				std::cout << current->data << " ";
				current = current->right;
			}
			else
			{
				pre = current->left;
				while (pre->right && pre->right != current)
					pre = pre->right;
				if (!pre->right)
				{
					pre->right = current;
					current = current->left;
				}
				else if (pre->right == current)
				{
					std::cout << current->data << " ";
					pre->right = nullptr;
					current = current->right;
				}
			}
		}
		std::cout << std::endl;
	}

	static void Print_PostOrder_Given_Pre_AND_In_Order(const std::vector<T>& pre, const std::vector<T>& in)
	{
		if (pre.size() != in.size())
			throw "Invalid Operation: Array sizes for PreOrder and InOrder traversals should be same.";
		if (pre.empty() || in.empty())
			throw "Invalid Operation: Empty array.";

		Print_PostOrder_Given_Pre_AND_In_Order_Util(pre.begin(), in.begin(), pre.size());

		std::cout << std::endl;
	}

	static std::vector<Leaf<T> *> Trees_Given_Inorder(const std::vector<T>& in, int start, int end)
	{
		std::vector<Leaf<T> *> trees;

		if (start > end)
		{
			trees.push_back(nullptr);
			return trees;
		}
		for (int i = start; i <= end; i++)
		{
			std::vector<Leaf<T> *> lTrees = Trees_Given_Inorder(in, start, i - 1);
			std::vector<Leaf<T> *> rTrees = Trees_Given_Inorder(in, i + 1, end);

			for (unsigned int j = 0; j < lTrees.size(); j++)
			{
				for (unsigned int k = 0; k < rTrees.size(); k++)
				{
					Leaf<T>* newLeaf = Leaf<T>::CreateLeaf(in[i]);

					newLeaf->left = lTrees[j];
					newLeaf->right = rTrees[k];

					trees.push_back(newLeaf);
				}
			}
		}
		return trees;
	}

	static void Print_Pre_From_Root(const Leaf<T>* root)
	{
		if (root == nullptr)
			return;
		std::cout << root->data << " ";
		Print_Pre_From_Root(root->left);
		Print_Pre_From_Root(root->right);
	}

	BinaryTree<T>& Construct_Tree_Sum_Of_Inoder_Successors_And_Predecessors()
	{
		if (!this->root)
			return *this;

		//construct vector for Inorder treaversal of the input tree
		std::vector<T> in;
		in.push_back(static_cast<T>(0));
		Inorder_Util(in, this->root);

		//add 0 to the beginning and end of inorder array
		in.push_back(static_cast<T>(0));

		//modifying tree
		int index = 1;
		Inorder_Util(in, this->root, &index);

		in.clear();
		std::vector<T>().swap(in);
		return *this;
	}

	Leaf<T>* Inorder_Successor_OF_Node_In_BT(const Leaf<T>* node) const
	{
		if (this->root == nullptr || node == nullptr)
			return nullptr;

		if (node->right)
		{
			Leaf<T>* successor = node->right;
			while (successor->left)
				successor = successor->left;
			return successor;
		}
		else
		{
			Stack<Leaf<T>* > *stack = new Stack<Leaf<T>* >();
			Rec_Search_Element(node, *stack, this->root);

			Leaf<T> *parent = nullptr, *child = nullptr;
			child = stack->Pop();
			
			while (!stack->IsEmpty())
			{
				parent = stack->Pop();
				if (parent->right == child)
					break;
				else {
					child = parent;
				}
			}
			return parent;
		}
	}

	void Print_Nth_Inorder_Node(int n)
	{
		if (this->root)
			Print_Nth_Inorder_Node_Util(this->root, n);
	}

	void Print_Nth_Postorder_Node(int n)
	{
		if (this->root)
			Print_Nth_Postorder_Node_Util(this->root, n);
	}

	void Print_Given_Level(int level)
	{
		if (this->root)
			Print_Given_Level_Util(this->root, level);
	}
	
	void 

	void Print_Level_Order_Rec()
	{
		if (this->root)
		{
			for
		}
	}
};

#endif