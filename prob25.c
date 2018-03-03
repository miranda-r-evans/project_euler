#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program to find the index of the first Fibonacci number with n digits */

typedef struct int_array {
	int *end;
	int *ptr;
	int *cap;
	int *buf;
} int_array;

void cpy_a_b(int_array *a, int_array *b)
{
	while (a->ptr >= a->cap)
	{
		*(b->ptr) = *(a->ptr);
		a->ptr--;
		b->ptr--;
	}

	b->cap = b->ptr + 1;
}

void add_a_b(int_array *a, int_array *b)
{
	int carry = 0;
	int digit;

	while (a->ptr >= a->cap)
	{
		digit = *(a->ptr) + *(b->ptr) + carry;
		if (digit > 9)
		{
			carry = 1;
			digit = digit - 10;
			if (a->ptr == a->cap)
				a->cap--;
		}
		else
			carry = 0;
		*(a->ptr) = digit;
       		a->ptr--;
		b->ptr--;
	}
}

void free_all(int_array *a, int_array *b, int_array *c)
{
	if (a != NULL)
	{
		if (a->buf != NULL)
			free(a->buf);

		free(a);
	}
	if (b != NULL)
	{
                if (b->buf != NULL)
                        free(b->buf);

                free(b);
	}
	if (c != NULL)
	{
                if (c->buf != NULL)
                        free(c->buf);

                free(c);
	}

	exit(0);
}

void reset_ptrs(int_array *a, int_array *b, int_array *c)
{
	a->ptr = a->end;
	b->ptr = b->end;
	c->ptr = c->end;
}

int main(int ac, char **av)
{
	const size_t n = (size_t)atoi(av[1]);
	int_array *i = malloc(sizeof(int_array));
	int_array *j = malloc(sizeof(int_array));
	int_array *tmp = malloc(sizeof(int_array));
	int k = 2;

	if (i == NULL || j == NULL || tmp == NULL)
		free_all(i, j, tmp);

	i->buf = malloc(sizeof(int) * n);
	j->buf = malloc(sizeof(int) * n);
	tmp->buf = malloc(sizeof(int) * n);

	if (i->buf == NULL || j->buf == NULL || tmp->buf == NULL)
		free_all(i, j, tmp);

	memset(i->buf, 0, n);
	memset(j->buf, 0, n);
	memset(tmp->buf, 0, n);

	i->end = i->buf + n - 1;
	j->end = j->buf + n - 1;
	tmp->end = tmp->buf + n - 1;

	*(i->end) = 1;
	*(j->end) = 1;

	reset_ptrs(i, j, tmp);

	i->cap = i->ptr;
	j->cap = j->ptr;
	tmp->cap = tmp->ptr;

	while (i->cap > i->buf)
	{
		reset_ptrs(i, j, tmp);
		cpy_a_b(i, tmp);
		reset_ptrs(i, j, tmp);
		add_a_b(i, j);
		reset_ptrs(i, j, tmp);
		cpy_a_b(tmp, j);
		k++;
	}
	printf("%d\n", k);

	return (0);
}
