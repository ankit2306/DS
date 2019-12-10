#ifndef __Dynamic_Programming__
#define __Dynamic_Programming__

class DynamicProgramming
{
public:
	static unsigned int UglyNumbers(int n)
	{
		unsigned int* ugly = new unsigned int[n];

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
			return  b > c ? c : b;
		else
			return b < c ? a : b;
	}
};

#endif