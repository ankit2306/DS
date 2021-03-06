#ifndef __STACK__
#define __STACK__

#include "Node.cpp"

template <typename T>
class Stack
{
private:
	Node<T>* head;

public:

	Stack* Push(T data)
	{
		Node<T>* oldHead = this->head;
		this->head = Node<T>::CreateNode(data);
		this->head->next = oldHead;
		return this;
	}

	T Pop()
	{
		T data = nullptr;
		if (!this->head)
			throw "Invalid Operation: Pop Operation on empty stack cannot be performed.";
		else
		{
			data = head->data;
			Node<T>* nextHead = this->head->next;
			head->DeleteNode();
			head = nextHead;
		}
		return data;
	}

	bool IsEmpty()
	{
		return this->head ? false : true;
	}
};

#endif