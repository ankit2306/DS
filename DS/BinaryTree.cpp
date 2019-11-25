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
};

#endif