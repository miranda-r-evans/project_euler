#include <stdio.h>

/* program to find the 1001'th prime */

int main(void)
{
	unsigned int i;
	unsigned int j = 1;
	unsigned int k;
	const unsigned int n = 10001;

	for (i = 0; i < n; i++)
	{
		j++;
		for(k = 2; k * k <= j; k++)
		{
			if (j % k == 0)
			{
				j++;
				k = 1;
			}
		}
	}
	printf("%u\n", j);

	return (0);
}
