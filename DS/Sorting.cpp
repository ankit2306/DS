#include <vector>
#include "Utility.h"

template <class T>
class Sorting {
private:
	template <class Func>
	static void RecBubbleSortUtil(std::vector<T>&, int rec, Func _compare);
public:
	template <class Func>
	static void SelectionSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void BubbleSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void RecBubbleSort(std::vector<T>& arr, Func _compare);
};

template<class T>
template<class Func>
void Sorting<T>::RecBubbleSortUtil(std::vector<T>& arr, int rec, Func _compare)
{
	if (rec == arr.size() - 1)
		return;

	for (int i = 0; i < arr.size() - rec - 1; i++)
		if (_compare(arr[i + 1], arr[i]))
			swap_arr(arr, i, i + 1);
	RecBubbleSortUtil(arr, rec + 1, _compare);
}

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
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (_compare(arr[j + 1], arr[j]))
				swap_arr(arr, j + 1, j);
		}
	}
}

template<class T>
template<class Func>
void Sorting<T>::RecBubbleSort(std::vector<T>& arr, Func _compare)
{
	if (arr.size() == 1)
		return;
	int rec = 0;
	for (int i = 0; i < arr.size() - rec - 1; i++)
		if (_compare(arr[i + 1], arr[i]))
			swap_arr(arr, i, i + 1);
	RecBubbleSortUtil(arr, rec + 1, _compare);
}