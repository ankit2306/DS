#ifndef __Dynamic_Programming__
#define __Dynamic_Programming__

#define MAX 100

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

	static unsigned int Binomial_Coeff(int n, int k)
	{
		unsigned int* bin{ new unsigned int[n + 1]{} };		// list initialization with dynamic memory allocation.	// all array members are assigned value 0.

		bin[0] = 1;
		for(int i = 1; i <= n; i++)
			for (int j = min_2(i, k); j > 0; j--)
			{
				bin[j] += bin[j - 1];
			}

		return bin[k];
	}
};

#endif