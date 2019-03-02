#include "ft_libft.h"

void	ft_arr_foreach(t_arr *arr, void (*func)())
{
	size_t	index;

	index = 0;
	while (index < arr->len)
	{
		func(arr->content[index]);
		index++;
	}
}
