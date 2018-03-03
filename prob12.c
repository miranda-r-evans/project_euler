#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

/* program to find first triangular number with n divisors - does not work for
   n = 1 */

int main(int ac, char **av)
{
const unsigned int n = atoi(av[1]);
	uint64_t i;
	uint64_t j;
	uint64_t l;
	unsigned int k = 0;

	for (i = 1; k <= n; i++)
	{
		k = 0;
		l = 0;
		for (j = 1; j <= i; j++)
		{
			l += j;
		}

		for (j = 1; j * j < l ; j++)
		{
			if (l % j == 0)
				k += 2;
		}
		if (l % j == 0)
			k++;
	}
	printf("%" PRId64 "\n", l);

	return (0);
}
