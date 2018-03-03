#include <stdio.h>

/* program to find the product of the pythagorean triplet whose sum is 1000 */

unsigned int sq_root(unsigned int c2)
{
	unsigned int i;

	for (i = 2; i * i < c2; i++)
		;

	if (c2 % i == 0)
		return (i);

	return (0);
}

int main(void)
{
	const unsigned int n = 1000;
	unsigned int a;
	unsigned int b;
	unsigned int c2;
	unsigned int c;

	for (a = 2; a <= n / 2; a++)
	{
		for (b = 2; b <= a; b++)
		{
			c2 = a * a + b * b;
			c = sq_root(c2);
			if (c != 0 && a + b + c == n)
			{
				printf("%u\n", a * b * c);
				return (0);
			}
		}
	}

	return (0);
}
