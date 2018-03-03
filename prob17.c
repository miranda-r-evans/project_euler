#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

/* function to print the sum of the letters of the names of the numbers from
   1 to 1000 */

int num_len(int i)
{
	if (i == 1)
		return (3);
	if (i == 2)
		return (3);
	if (i == 3)
		return (5);
	if (i == 4)
		return (4);
	if (i == 5)
		return (4);
	if (i == 6)
		return (3);
	if (i == 7)
		return (5);
	if (i == 8)
		return (5);
	if (i == 9)
		return (4);
	if (i == 10)
		return (3);
	if (i == 11)
		return (6);
	if (i == 12)
		return (6);
	if (i == 13)
		return (8);
	if (i == 14)
		return (8);
	if (i == 15)
		return (7);
	if (i == 16)
		return (7);
       	if (i == 17)
		return (9);
	if (i == 18)
		return (8);
	if (i == 19)
		return (8);
	if (i == 20)
		return (6);
	if (i == 30)
		return (6);
	if (i == 40)
		return (5);
	if (i == 50)
		return (5);
	if (i == 60)
		return (5);
	if (i == 70)
		return (7);
	if (i == 80)
		return (6);
	if (i == 90)
		return (6);

	return (0);
}

int main (void)
{
	const int n = 1000;
	int i;
	int d;
	int sum = 0;
	bool and;

	for (i = 1; i <= n; i++)
	{
		d = i;
		and = false;

		if (d > 999)
		{
			sum += 8;
			sum += num_len(d / 1000);
			d = i % 1000;
		}

		if (d > 99)
		{
			sum += 7;
			sum += num_len(d / 100);
			d = i % 100;
		}

		if (d > 19)
		{
			sum += (num_len((d / 10) * 10));
			d = i % 10;
			if (i > 99)
				and = true;
		}

		if (d < 20)
		{
			sum += num_len(d);
			if (d != 0 && i > 99)
				and = true;
		}

		if (and == true)
			sum += (3);
       	}

       	printf("%d\n", sum);

	return (0);
}
