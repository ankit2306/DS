class Node {
public:
	Node* next;
	int data;

	static Node* CreateNode(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		return newNode;
	}

	void DeleteNode()
	{
		delete this;
	}
};