#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program to find the smallest number that can be cleanly divided from the
   number 1 to n */

int main(int ac, char **av)
{
	const unsigned int n = atoi(av[1]);
	unsigned int i = 2;
	unsigned int j = 2;
	unsigned int end = 1;

	for (; i <= n; i++)
	{
		while (end % i != 0)
       		{
       			if (end * j % i == 0)
			{
       				end *= j;
				j = 2;
			}
       			else
       				j++;
       		}
	}
	printf("%d\n", end);

	return (0);
}
