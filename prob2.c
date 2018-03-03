#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* finds the sum of even Fibonacci numbers whose values do not exceed n */

int main(int ac, char **av)
{
	unsigned int i = 1;
	unsigned int j = 1;
	unsigned int temp;
	unsigned int sum = 0;
	int trak = 1;
	const unsigned int n = atoi(av[1]);

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
