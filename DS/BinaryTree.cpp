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
		Leaf<T>* current, * left;
		current = root;
		if (current)
		{
			stack.Push(current);
			while (!stack.IsEmpty() || current)
			{
				while (current)
				{
					stack.Push(current);
					current = current->left;
				}

				Leaf<T>* poppedData = stack.Pop();
				std::cout << poppedData << " ";
				current = current->right;
			}
		}
	}
};