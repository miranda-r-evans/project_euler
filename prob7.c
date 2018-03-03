#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program to find the n'th prime */

int main(int ac, char **av)
{
	unsigned int i;
	unsigned int j = 1;
	unsigned int k;
	const unsigned int n = atoi(av[1]);

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
