#pragma once
#ifndef __UTILITY_H__
#define __UTILITY_H__

#include<iostream>

static int max_2(int a, int b)
{
	return a > b ? a : b;
}

static unsigned int abs_diff(int a, int b)
{
	return a > b ? a - b : b - a;
}

template <typename T>
static void print_2d(T** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

static unsigned int min_3(unsigned int a, unsigned int b, unsigned int c)
{
	if (a > b)
		return  c > b ? b : c;
	else
		return a < c ? a : c;
}

static int min_2(int a, int b)
{
	return a < b ? a : b;
}

static int max_3(int a, int b, int c)
{
	if (a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

template <class T>
static void swap_arr(std::vector<T>& arr, int index1, int index2)
{
	arr[index1] += arr[index2];
	arr[index2] = arr[index1] - arr[index2];
	arr[index1] -= arr[index2];
}

#endif // !__UTILITY_H__