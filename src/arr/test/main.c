#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ft_libft.h"

static char		*tests[] = {"Chaine1", "Chaine2", "Chaine3", 0x0};

int ft_arr_pushback_test(t_arr **arr)
{
	ssize_t  new;
	t_arr   *origin;

	new = 0x0;
	origin = *arr;
	new = ft_arr_pushback(arr, strdup(tests[0]));
	assert(origin == *arr);
	assert(new >= 0);
	assert(origin->len == 1);
	assert(origin->first == (*arr)->content[new]);
	assert(origin->last == (*arr)->content[new]);
	assert(!strcmp(origin->content[0], tests[0]));

	new = ft_arr_pushback(arr, strdup(tests[1]));
	assert(origin == *arr);
	assert(new >= 0);
	assert(origin->len == 2);
	assert(origin->max == 2);
	assert(origin->first != (*arr)->content[new]);
	assert(origin->last == (*arr)->content[new]);
	assert(!strcmp(origin->content[1], tests[1]));

	new = ft_arr_pushback(arr, strdup(tests[2]));
	assert(origin != *arr);
	origin = *arr;
	assert(new >= 0);
	assert(origin->len == 3);
	assert(origin->max == 5);
	assert(origin->first != 0x0);
	assert(origin->last != 0x0);
	assert(origin->first != origin->last);
	assert(!strcmp(origin->content[0], tests[0]));
	assert(!strcmp(origin->content[1], tests[1]));
	assert(!strcmp(origin->content[2], tests[2]));
	return (0);
}

int ft_arr_new_test(t_arr **arr, size_t size)
{
	ft_arr_new(arr, size);
	assert(*arr != 0x0);
	assert((*arr)->max == size);
	assert((*arr)->first == 0x0);
	assert((*arr)->last == 0x0);
	return (0);
}

int ft_arr_clear_test(t_arr *arr)
{
	ft_arr_clear(arr, ft_memdel);
	assert(arr->len == 0);
	assert(arr->first == 0x0);
	assert(arr->last == 0x0);
	assert(arr->content[0] == 0x0);
	return (0);
}

int ft_arr_join_test()
{
	t_arr *arr1;
	t_arr *arr2;

	arr1 = 0x0;
	arr2 = 0x0;
	ft_arr_new(&arr1, 1);
	ft_arr_new(&arr2, 2);
	assert(arr1 && arr2);
	ft_arr_pushback(&arr1, strdup(tests[1]));
	ft_arr_pushback(&arr2, strdup(tests[2]));
	arr1 = ft_arr_join(arr1, arr2);
	assert(arr1 == arr2);
	assert(arr1->len == 2);
	assert(!strcmp(arr1->content[0], tests[1]));
	assert(!strcmp(arr1->content[1], tests[2]));
	ft_arr_del(&arr1, ft_memdel);

	ft_arr_new(&arr1, 2);
	ft_arr_new(&arr2, 1);
	assert(arr1 && arr2);
	ft_arr_pushback(&arr1, strdup(tests[1]));
	ft_arr_pushback(&arr2, strdup(tests[2]));
	arr2 = ft_arr_join(arr1, arr2);
	assert(arr1 == arr2);
	assert(arr1->len == 2);
	assert(!strcmp(arr1->content[0], tests[1]));
	assert(!strcmp(arr1->content[1], tests[2]));
	ft_arr_del(&arr2, ft_memdel);

	ft_arr_new(&arr1, 1);
	ft_arr_new(&arr2, 1);
	assert(arr1 && arr2);
	ft_arr_pushback(&arr1, strdup(tests[1]));
	ft_arr_pushback(&arr2, strdup(tests[2]));
	arr2 = ft_arr_join(arr1, arr2);
	assert(arr2->len == 2);
	assert(!strcmp(arr2->content[0], tests[1]));
	assert(!strcmp(arr2->content[1], tests[2]));
	ft_arr_del(&arr2, ft_memdel);
	return (0);
}

int main(int argc, char **argv)
{
	t_arr *arr;

	(void)argc;
	(void)argv;
	arr = 0x0;
	printf("Start test on arr\n");
	if (!ft_arr_new_test(&arr, 2))
	{
		printf("ft_arr_new_test:OK\n");
		ft_arr_pushback_test(&arr);
		printf("ft_arr_pushback_test:OK\n");
		ft_arr_clear_test(arr);
		printf("ft_arr_clear_test:OK\n");
		ft_arr_join_test();
		printf("ft_arr_join_test:OK\n");
		ft_arr_del(&arr, ft_memdel);
	}
	else
		printf("ft_arr_new_test:KO\n");
	return (0);
}
