#ifndef __Dynamic_Programming__
#define __Dynamic_Programming__

#define MAX 100
#include <iostream>
#include <algorithm>
#include <vector>
class DynamicProgramming
{
private:
	static void Display(const std::vector<int>& subsets)
	{
		for (int i = 0; i < subsets.size(); i++)
		{
			std::cout << subsets[i] << " ";
		}
		std::cout << std::endl;
	}

	static void Print_All_Subsets_With_Given_Sum_Rec(int S[], bool** dp, int size, int sum, std::vector<int>& subsets)
	{
		if(size == 1 && sum!=0 && dp[1][sum])
		{
			subsets.push_back(S[size - 1]);
			Display(subsets);
			subsets.pop_back();
			return;
		}
		if (sum == 0 && size == 0)
		{
			Display(subsets);
			return;
		}

		//exclude element from subset
		if(dp[size - 1][sum])
			Print_All_Subsets_With_Given_Sum_Rec(S, dp, size - 1, sum, subsets);

		//include element in subset
		if(sum >= S[size - 1] && dp[size - 1][sum - S[size - 1]])
		{
			subsets.push_back(S[size - 1]);
			Print_All_Subsets_With_Given_Sum_Rec(S, dp, size - 1, sum - S[size - 1], subsets);
			subsets.pop_back();
		}
	}

	static int max_2(int a, int b)
	{
		return a > b ? a : b;
	}

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

	static int Count_Friends_Pairings(int n)
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

	static bool Subset_Sum(int S[], int size, int sum)
	{
		bool is_subset_present = false;
		bool** dp_table{ new bool* [size + 1]{} };
		for (int i = 0; i <= size; i++)
			dp_table[i] = new bool[sum + 1]{true};

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= sum; j++)
			{
				if (j >= S[i - 1])
					dp_table[i][j] = dp_table[i - 1][j] || dp_table[i -1][j - S[i - 1]];
				else
					dp_table[i][j] = dp_table[i - 1][j];
			}
		}
		if (dp_table[size][sum])
			is_subset_present = true;
		
		for (int i = 0; i <= size; i++)
			delete[] dp_table[i];
		delete[] dp_table;

		return is_subset_present;
	}

	static int Largest_Divisible_Pair(int S[], int size)
	{
		std::sort(S, S + size, [](const int& a, const int& b) -> bool {return a < b; });	   //used a predicate
		/*for (int i = 0; i < size; i++)
			std::cout << S[i] << " ";*/

		int* ldp{ new int[size] {} };
		ldp[size - 1] = 1;

		for (int i = size - 2; i >= 0; i--)
		{
			int max_multiple = 0;
			for (int j = i + 1 ; j < size; j++)
			{
				if (S[j] % S[i]) {
					if (ldp[j] > max_multiple)
						max_multiple = ldp[j];
				}
				ldp[i] = max_multiple + 1;
			}
		}
		int max_subarray = *std::max_element(ldp, ldp + size);
		delete[] ldp;
		return max_subarray;
	}

	static void Print_All_Subsets_With_Given_Sum(int S[], int size, int sum)
	{
		bool** dp_table{ new bool* [size + 1]{} };
		for (int i = 0; i <= size; i++)
			dp_table[i] = new bool[sum + 1]{ true };

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= sum; j++)
			{
				if (j >= S[i - 1])
				{
					dp_table[i][j] = dp_table[i - 1][j] || dp_table[i - 1][j - S[i - 1]];
				}
				else
					dp_table[i][j] = dp_table[i - 1][j];
			}
		}

		// for (int i = 0; i <= size; i++)
		// {
		// 	for (int j = 0; j <= sum; j++)
		// 	{
		// 		std::cout << dp_table[i][j] << " ";
		// 	}
		// 	std::cout << std::endl;
		// }

		//start backtracing sum path
		std::vector<int> Subsets;
		Print_All_Subsets_With_Given_Sum_Rec(S, dp_table, size, sum, Subsets);
	}

	static int Cut_Rod(int Price[], int size)
	{
		int* dp{ new int[size + 1] {} };

		for (int i = 1; i <= size; i++)
		{
			int max_cost = 0;
			for (int j = 0; j < i; j++)
			{
				max_cost = max_2(max_cost, Price[j] + dp[i - j - 1]);
			}
			dp[i] = max_cost;
		}
		int max_cost = dp[size];
		delete[] dp;
		return max_cost;
	}
};

#endif