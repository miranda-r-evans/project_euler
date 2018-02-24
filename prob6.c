#include <stdio.h>

/* finds the different of the square of the sum and the sum of the squares of
   the numbers from 1 to 100 */

int main(void)
{
	unsigned int sum_of_sq = 0;
	unsigned int sq_of_sum = 0;
	unsigned int i;
	const unsigned int n = 100;

	for (i = 1; i <= n; i++)
	{
		sum_of_sq += i * i;
	}

	for (i = 1; i <= n; i++)
	{
		sq_of_sum += i;
	}

	sq_of_sum *= sq_of_sum;

	printf("%d\n", sq_of_sum - sum_of_sq);

	return (0);
}
