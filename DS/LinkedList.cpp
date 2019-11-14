#include "Node.cpp"
#include <iostream>

class LinkedList
{
public:
	Node* head;

	static LinkedList* CreateNewLList(int data)
	{
		LinkedList* LList = new LinkedList();
		LList->head = Node::CreateNode(data);
		return LList;
	}

	void DeleteLList()
	{
		if (!this->head)
			return;

		Node* next = nullptr;
		while (head)
		{
			next = this->head->next;
			head->DeleteNode();
			head = next;
		}
	}

	void DeleteElementInLList(int data)
	{
		if (!this->head)
			return;

		// if data is the first element of list
		if (this->head->data == data)
		{
			Node* next = this->head->next;
			this->head->DeleteNode();
			this->head = next;
		}
		else
		{
			Node* next = this->head;
			// if data occurs anywhere else in the list
			while (next && next->next)
			{
				if (next->next->data == data)
				{
					Node* nextElement = next->next->next;
					next->next->DeleteNode();
					next->next = nextElement;
				}
				next = next->next;
			}
		}
	}

	LinkedList* AppendElementInLList(int data)
	{
		LinkedList* updatedlist = this;
		if (!this)
		{
			updatedlist = CreateNewLList(data);
		}
		else
		{
			Node* head = this->head;
			while (head && head->next)
			{
				head = head->next;
			}
			head->next = Node::CreateNode(data);
		}

		return updatedlist;
	}

	LinkedList* PrependElementInLList(int data)
	{
		LinkedList* updatedList = this;
		if (!this)
		{
			updatedList = CreateNewLList(data);
		}
		else
		{
			Node* oldHead = this->head;
			this->head = Node::CreateNode(data);
			this->head->next = oldHead;
		}
		return this;
	}

	void printLList()
	{
		Node* head = this->head;
		while (head)
		{
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
};