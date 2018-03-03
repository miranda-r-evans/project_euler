#include <stdio.h>

/* program to find the sum of the digits of 2^1000 */

int main(void)
{
	int array[400] = { 0 };
	int *arr_end = array + 398;
	int *arr_ptr;
	int *arr_cap = arr_end - 2;
	const int n = 1000;
	int i;
	int digit;
	int carry = 0;
	int sum = 0;

	*arr_end = 1;
	arr_cap = arr_end;

	for (i = 0; i < n; i++)
	{
		for (arr_ptr = arr_end; arr_ptr >= arr_cap; arr_ptr--)
		{
			digit = *arr_ptr * 2 + carry;
			if (digit > 9)
			{
				digit -= 10;
				carry = 1;
				if (arr_ptr == arr_cap)
					arr_cap--;
			}
			else
				carry = 0;
			*arr_ptr = digit;
		}
	}

	while (arr_ptr <= arr_end)
	{
		sum += *arr_ptr;
		arr_ptr++;
	}
	printf("%d\n", sum);

	return (0);
}
