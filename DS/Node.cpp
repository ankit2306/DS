#ifndef __NODE__
#define __NODE__

template <typename T>
class Node
{
	public:
		Node<T>* next;
		T data;
	
		static Node<T>* CreateNode(T data)
		{
			Node<T>* newNode = new Node<T>();
			newNode->data = data;
			newNode->next = nullptr;
			return newNode;
		}
	
		void DeleteNode()
		{
			delete this;
		}
};

#endif