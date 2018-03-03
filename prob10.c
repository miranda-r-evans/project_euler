#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

/* program to find the sum of the primes under n */

int main(int ac, char **av)
{
	const unsigned int n = atoi(av[1]);
	unsigned int i;
	unsigned int j;
	uint64_t sum = 0;
	int _bool;

	for (i = 2; i < n; i++)
	{
		_bool = 0;
		for (j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				_bool = 1;
				break;
			}

		}

		if (_bool == 0)
		{
			sum += i;
		}
	}
	printf("%" PRId64 "\n", sum);

	return (0);
}
