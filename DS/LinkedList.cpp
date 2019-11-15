#include "Node.cpp"
#include <iostream>

template <typename T>
class LinkedList
{
public:
	Node<T>* head;

	void DeleteLList()
	{
		if (!this->head)
			return;

		Node<T>* next = nullptr;
		while (head)
		{
			next = this->head->next;
			head->DeleteNode();
			head = next;
		}
	}

	void DeleteElementInLList(T data)
	{
		if (!this->head)
			return;

		// if data is the first element of list
		if (this->head->data == data)
		{
			Node<T>* next = this->head->next;
			this->head->DeleteNode();
			this->head = next;
		}
		else
		{
			Node<T>* next = this->head;
			// if data occurs anywhere else in the list
			while (next && next->next)
			{
				if (next->next->data == data)
				{
					Node<T>* nextElement = next->next->next;
					next->next->DeleteNode();
					next->next = nextElement;
				}
				next = next->next;
			}
		}
	}

	LinkedList<T>* AppendElementInLList(T data)
	{
		if (!this->head)
		{
			this->head = Node<T>::CreateNode(data);
		}
		else
		{
			Node<T>* current = this->head;
			while (head && head->next)
			{
				head = head->next;
			}
			head->next = Node<T>::CreateNode(data);
		}
		return this;
	}

	LinkedList<T>* PrependElementInLList(T data)
	{
		Node<T>* oldHead = this->head;
		this->head = Node<T>::CreateNode(data);
		this->head->next = oldHead;
		return this;
	}

	void printLList()
	{
		Node<T>* head = this->head;
		while (head)
		{
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
};