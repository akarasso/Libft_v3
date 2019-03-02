#include "ft_libft.h"

void	ft_arr_clear(t_arr *arr, void (*func)())
{
	size_t	curr;

	curr = 0;
	while (curr < arr->len)
	{
		func(&arr->content[curr]);
		curr++;
	}
	arr->first = 0x0;
	arr->last = 0x0;
	arr->len = 0;
}
