#include <vector>

template <class T>
class Sorting {
private:

public:
	static void SelectionSort(std::vector<T> arr);
};

template<class T>
void Sorting<T>::SelectionSort(std::vector<T> arr)
{
	int min_index;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[i])
				min_index = j;
		}
		if(i != min_index)
		{
			arr[i] += arr[min_index];
			arr[min_index] = arr[i] - arr[min_index];
			arr[i] -= arr[min_index];
		}
	}
}