#include <stdio.h>
#include <math.h>

/* finds the largest palindrome number that is the product of two 3-digit numbers */

int check_pal(char *str, char *str_end)
{
	while (str < str_end)
	{
		if (*str != *str_end)
		return (0);

		str++;
		str_end--;
	}

	return (1);
}

int main(void)
{
	int i = 999;
	int j = 999;
	int n;
	char str[7];
	char *str_end;
	int biggest[] = { 0, 0, 0 };

	while (i > 99)
	{
		j = i;
		while (j > 99)
		{
			if (j < biggest[2])
				break;
			n = i * j;
			if (n < 100000)
				str_end = &str[4];
			else
				str_end = &str[5];
			sprintf(str, "%d", n);
			if (check_pal(str, str_end) == 1)
			{
				if (n > biggest[0])
				{
					biggest[0] = n;
					biggest[1] = i;
					biggest[2] = j;
					break;
				}
			}
			j--;
		}
		i--;
	}
	printf("%d\n", biggest[0]);
	return (0);
}
