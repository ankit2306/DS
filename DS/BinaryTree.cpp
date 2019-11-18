#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include "Leaf.cpp"
#include "Stack.cpp"
#include <iostream>

template <typename T>
class BninaryTree
{
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

	void Rec_Inorder(Leaf<T>* leaf)
	{
		if (leaf == nullptr)
			return;
		Rec_Inorder(leaf->left);
		std::cout << leaf->data << " ";
		Rec_Inorder(leaf->right);
	}

	void Iterative_Inorder()
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
};

#endif