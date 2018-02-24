#include <stdio.h>

int main(void)
{
	const unsigned int n = 20;
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
