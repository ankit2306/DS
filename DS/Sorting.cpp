#include <vector>
#include "Utility.h"

template <class T>
class Sorting {
private:
	template <class Func>
	static void RecBubbleSortUtil(std::vector<T>&, int rec, Func _compare);
	template <class Func>
	static void Merge(std::vector<T>& arr, int L, int M, int R, Func _compare);
public:
	template <class Func>
	static void SelectionSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void BubbleSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void RecBubbleSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void InsertionSort(std::vector<T>& arr, Func _compare);
	template <class Func>
	static void MergeSort(std::vector<T>& arr, int L, int R, Func _compare);
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
void Sorting<T>::Merge(std::vector<T>& arr, int L, int M, int R, Func _compare)
{
	std::vector<T> arr1, arr2;
	copy(arr.begin() + L, arr.begin() + M + 1, back_inserter(arr1));
	copy(arr.begin() + M + 1, arr.begin() + R + 1, back_inserter(arr2));

	int left = 0, right = 0, index = L;
	while (left < arr1.size() && right < arr2.size())
	{
		if (_compare(arr1[left], arr2[right]))
		{
			arr[index] = arr1[left];
			left++;
			index++;
		}
		else
		{
			arr[index] = arr2[right];
			right++;
			index++;
		}
	}
	while (left < arr1.size())
	{
		arr[index] = arr1[left];
		left++;
		index++;
	}
	while (right < arr2.size())
	{
		arr[index] = arr2[right];
		right++;
		index++;
	}
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

template<class T>
template<class Func>
void Sorting<T>::InsertionSort(std::vector<T>& arr, Func _compare)
{
	for (int i = 1; i < arr.size(); i++)
	{
		if (_compare(arr[i], arr[i - 1]))
		{
			int j = i - 1;
			T key = arr[i];
			while (j > 0 && arr[j - 1] > key)
			{
				arr[j] = arr[j - 1];
				j--;
			}																    
			arr[j] = key;
		}
	}
}

template<class T>
template<class Func>
void Sorting<T>::MergeSort(std::vector<T>& arr,int L, int R, Func _compare)
{
	if (L >= R)
		return;

	int M = L + (R - L) / 2;
	MergeSort(arr, L, M, _compare);
	MergeSort(arr, M + 1, R, _compare);

	Merge(arr, L, M, R, _compare);
}
