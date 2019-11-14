#include "Node.cpp"

template <typename T>
class Stack
{
private:
	Node* head;

public:

	static Stack* CreateNewStack(T data)
	{
		Stack* stack = new Stack();
		stack->head = Node::CreateNode(data);
		return stack;
	}

	Stack* Push(T data)
	{
		Stack* updatedStack = this;
		if (!this)
		{
			updatedStack = CreateNewStack(data);
		}
		else
		{
			Node* oldHead = this->head;
			this->head = Node::CreateNode(data);
			this->head->next = oldHead;
		}
		return this;
	}

	T Pop()
	{
		if (!this || !this->head)
			return nullptr;
		else
		{
			T data = head->data;
			Node* nextHead = this->head->next;
			head->DeleteNode();
			head = nextHead;
		}
		return T;
	}

	bool IsEmpty()
	{
		return this->head ? true : false;
	}
};