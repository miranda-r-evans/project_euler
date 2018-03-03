#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program to find the longest collatz sequence under a given number */

int main(int ac, char **av)
{
	const unsigned int n = atoi(av[1]) - 1;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int longest[] = { 0, 0 };

	for (i = n; i >= n / 2 ; i--)
	{
		for (j = i, k = 1; j > 0; k++)
		{
			if (j % 2 == 0)
				j = j / 2;
			else if (j == 1)
				break;
			else
				j = j * 3 + 1;
		}
		if (k > longest[0])
		{
			longest[0] = k;
			longest[1] = i;
		}
	}
	printf("%u\n", longest[1]);

	return (0);
}
