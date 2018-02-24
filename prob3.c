#include <stdio.h>
#include <inttypes.h>

/* find the largest prime factor of 600851475143 */

int main(void)
{
	uint64_t n = 600851475143;
	unsigned int i = 2;

	while (i * i < n)
	{
		if (n % i == 0)
		{
			n = n / i;
			i = 2;
		}
		else
			i++;
	}

	printf("%" PRId64 "\n", n);

	return (0);
}
