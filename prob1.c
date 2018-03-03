#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* find the sum of natural numbers less than n */

int main(int ac, char **av)
{
	unsigned int sum = 0;
	unsigned int i;
	unsigned int j;
	const unsigned int n = atoi(av[1]);

	for (i = 3; i < n; i += 3)
	{
		sum += i;
	}

	for (i = 5; i < n; i += 5)
	{
		if (j == 2)
			j = 0;
		else
		{
			sum += i;
			j++;
		}
	}

	printf("%d\n", sum);

	return (0);
}
