#include "Leaf.cpp"
#include "Stack.cpp"
#include <iostream>

class BninaryTree
{
public:
	Leaf* root;

	void RecInorderTraversal()
	{
		if (root)
		{
			Rec_Inorder(root);
			std::cout << std::endl;
		}
	}

	void Rec_Inorder(Leaf* leaf)
	{
		if (leaf == nullptr)
			return;
		Rec_Inorder(leaf->left);
		std::cout << leaf->data << " ";
		Rec_Inorder(leaf->right);
	}

	void Iterative_Inorder()
	{
		Stack<Leaf*>* stack = new Stack<Leaf*>();
		Leaf *current, *left, *right;
		current = root;
		while (!stack->IsEmpty() && current)
		{
			left = current->left;
			right = current->right;
			if (left)
			{
				stack->Push(right);
				stack->Push(current);
				current = left;
				continue;
			}
			else
			{
				Leaf* popped = stack->Pop();
				std::cout << popped->data << " ";
				stack->
			}
		}
	}
};