#ifndef __Dynamic_Programming__
#define __Dynamic_Programming__

#define MAX 100
#include <iostream>
class DynamicProgramming
{
public:
	static unsigned int UglyNumbers(int n)
	{
		unsigned int* ugly = new unsigned int[n] {0};
		ugly[0] = 1;
		int i2 = 0, i3 = 0, i5 = 0;
		for (int index = 1; index < n; index++)
		{
			for (i2, i3, i5; ugly[i2] * 2 <= ugly[index - 1] || ugly[i3] * 3 <= ugly[index - 1] || ugly[i5] * 5 <= ugly[index - 1];)
			{
				if (ugly[i2] * 2 <= ugly[index - 1])
					i2++;
				if (ugly[i3] * 3 <= ugly[index - 1])
					i3++;
				if (ugly[i5] * 5 <= ugly[index - 1])
					i5++;
			}
			unsigned int u1, u2, u3;
			u1 = 2 * ugly[i2];
			u2 = 3 * ugly[i3];
			u3 = 5 * ugly[i5];
			ugly[index] = min_3(u1, u2, u3);
		}
		return ugly[n - 1];
	}

	static unsigned int min_3(unsigned int a, unsigned int b, unsigned int c)
	{
		if (a > b)
			return  c > b ? b : c;
		else
			return a < c ? a : c;
	}

	static int Fib_Using_Matrix_Expansion(int n)
	{
		static int f[MAX] = { 0 };
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return f[n] = 1;
		if (f[n])
			return f[n];
		int k = n & 1 ? (n + 1) / 2 : n / 2;

		f[n] = n & 1 ? Fib_Using_Matrix_Expansion(k) * Fib_Using_Matrix_Expansion(k) + Fib_Using_Matrix_Expansion(k - 1) * Fib_Using_Matrix_Expansion(k - 1) : (2 * Fib_Using_Matrix_Expansion(k - 1) + Fib_Using_Matrix_Expansion(k)) * Fib_Using_Matrix_Expansion(k);

		return f[n];
	}

	static unsigned int Catlan(int n)
	{
		static unsigned int f[MAX] = { 0 };
		f[0] = 1;

		if (n < 0)
			return 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
				f[i] += f[j] * f[i - j - 1];
		}

		return f[n];
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

	static unsigned int Binomial_Coeff(int n, int k)
	{
		unsigned int* bin{ new unsigned int[n + 1]{} };		// list initialization with dynamic memory allocation.	// all array members are assigned value 0.

		bin[0] = 1;
		for(int i = 1; i <= n; i++)
			for (int j = min_2(i, k); j > 0; j--)
			{
				bin[j] += bin[j - 1];
			}
		int bin_coeff = bin[k];
		delete[] bin;
		return bin_coeff;
	}

	static unsigned long long int Permutation_Coeff(int n, int k)
	{
		unsigned long long int permutaion_n_k = 1;

		for (int i = n; i > n - k; i++)
			permutaion_n_k *= i;

		return permutaion_n_k;
	}

	static int Get_Max_Gold(int gold[][MAX], int m, int n)
	{
		int** maxgold{ new int*[m] {} };
		for (int i = 0; i < m; i++)
			maxgold[i] = new int[n] {};

		for (int col = n - 1; col >= 0; col--)
		{
			for (int row = 0; row < m; row++)
			{
				int right_up = (col == n - 1 || row == 0) ? 0 : maxgold[row - 1][col + 1];

				int right = (col == n - 1) ? 0 : maxgold[row][col + 1];

				int right_down = (col == n - 1 || row == m - 1) ? 0 : maxgold[row + 1][col + 1];

				maxgold[row][col] = gold[row][col] + max_3(right_up, right, right_down);
			}
		}

		/*for (int col = 0; col < m; col++)
		{
			
			std::cout << std::endl;
		}*/

		int gold_collected = 0;
		for (int i = 0; i < m; i++)
		{
			if (maxgold[i][0] > gold_collected)
				gold_collected = maxgold[i][0];
		}

		for (int i = 0; i < m; i++)
			delete[] maxgold[i];
		delete[] maxgold;

		return gold_collected;
	}

	static int Coin_Change(int S[], int size, int sum)
	{
		int* change{ new int[sum + 1]{1}};
		for (int i = 0; i < size; i++)
		{
			for (int j = S[i]; j <= sum; j++)
			{
				change[j] += change[j - S[i]];
			}
		}
		int n = change[sum];
		delete[] change;
		return n;
	}

	int Count_Friends_Pairings(int n)
	{
		int a = 1, b = 2, c = 0;
		if (n <= 2) {
			return n;
		}
		for (int i = 3; i <= n; i++) {
			c = b + (i - 1) * a;
			a = b;
			b = c;
		}
		return c;
	}


};

#endif