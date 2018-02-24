#include <stdio.h>

/* finds the sum of even Fibonacci numbers whose values do not exceed 4000000 */

int main(void)
{
	unsigned int i = 1;
	unsigned int j = 1;
	unsigned int temp;
	unsigned int sum = 0;
	int trak = 1;
	const unsigned int n = 4000000;

	while (i <= n)
	{
		if (trak == 2)
		{
			sum += i;
			trak = 0;
		}
		else
			trak++;

		temp = i;
		i += j;
		j = temp;
	}
	printf("%u\n", sum);

	return (0);
}
