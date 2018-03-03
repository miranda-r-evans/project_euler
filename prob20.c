#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program to find the sum of a factorial's digits */

int main(int ac, char **av)
{
	const unsigned int n = atoi(av[1]);
	unsigned int i;
	unsigned int carry;
	unsigned int digit;
	unsigned int sum = 0;
	int buffer[500] = { 0 };
	int *start = buffer;
	int *end = buffer + 498;
	int *iter = end;
	int *cap = iter;

	*end = 1;

	for (i = 1; i <= n; i++)
	{
		iter = end;
		carry = 0;
		while (iter >= cap)
		{
			digit = (*iter) * i + carry;
			if (digit > 9)
			{
				carry = digit / 10;
				digit = digit % 10;
				if (iter == cap)
					cap--;
			}
			else
				carry = 0;
			*iter = digit;
			iter--;
		}
	}

	while (iter <= end)
	{
		sum += *iter;
		iter++;
	}

	printf("%u\n", sum);

	return (0);
}
