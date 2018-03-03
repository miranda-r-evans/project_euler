#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program to find the sum of the amicable numbers under n */

int div_sum(unsigned int j)
{
	unsigned int fac_sum = 1;
	unsigned int i = 2;

	for (i = 2; i * i < j; i++)
	{
		if (j % i == 0)
			fac_sum += i + (j / i);
	}

	if (j % i == 0)
		fac_sum += 1;

	return (fac_sum);
}

int main(int ac, char **av)
{
	const unsigned int n = atoi(av[1]);
	unsigned int i;
	unsigned int temp;
	unsigned int am_sum = 0;

	for (i = 2; i <= n; i++)
	{
		temp = div_sum(i);
		if (i < temp)
		{
			if (div_sum(temp) == i)
			{
				am_sum += i;
				if (temp < n)
					am_sum += temp;
			}
		}
	}

	printf("%d\n", am_sum);

	return(0);
}
