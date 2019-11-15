#include "Node.cpp"

template <typename T>
class Stack
{
private:
	Node<T>* head;

public:

	Stack* Push(T data)
	{
		Node* oldHead = this->head;
		this->head = Node::CreateNode(data);
		this->head->next = oldHead;
		return this;
	}

	T Pop()
	{
		if (!this->head)
			throw "Invalid Operation: Pop Operation on empty stack cannot be performed.";
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