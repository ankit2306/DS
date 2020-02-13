#include <vector>
#include "Utility.h"

template <class T>
class Sorting {
private:

public:
	template <class Func>
	static void SelectionSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void BubbleSort(std::vector<T>& arr, Func _compare);
};

template<class T>
template<class Func>
void Sorting<T>::SelectionSort(std::vector<T>& arr, Func _compare)
{
	int index;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (_compare(arr[j], arr[i]))
				index = j;
		}
		if(i != index)
		{
			swap_arr(arr, i, index);
		}
	}
}

template<class T>
template<class Func>
void Sorting<T>::BubbleSort(std::vector<T>& arr, Func _compare)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (_compare(arr[j], arr[i]))
				swap_2(arr.begin() + i, arr.begin() + j);
		}
	}
}
