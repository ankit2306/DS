template <typename T>
class Leaf
{
public:
	Leaf<T>* left;
	Leaf<T>* right;
	T data;

	static Leaf<T>* CreateLeaf(T data)
	{
		Leaf<T>* newLeaf = new Leaf<T>();
		newLeaf->data = data;
		newLeaf->left = nullptr;
		newLeaf->right = nullptr;
		return newLeaf;
	}

	void DeleteNode()
	{
		delete this;
	}
};