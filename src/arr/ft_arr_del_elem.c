#include "ft_libft.h"

void	ft_arr_del_elem(t_arr *arr, size_t index, void (*func)())
{
 	if (index < arr->len)
	{
		func(&arr->content[index]);
		arr->len--;
		while (index < arr->len)
		{
			arr->content[index] = arr->content[index + 1];
			index++;
		}
	}
}
