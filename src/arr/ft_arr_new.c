#include "ft_libft.h"

t_arr	*ft_arr_new(t_arr **arr, size_t size)
{
	if (!(*arr = malloc(sizeof(**arr))))
		return (*arr);
	if (!((*arr)->content = ft_memalloc(sizeof(void*) * (size + 1))))
	{
		free(*arr);
		return (0x0);
	}
	(*arr)->first = 0x0;
	(*arr)->last = 0x0;
	(*arr)->len = 0;
	(*arr)->max = size;
	return *arr;
}
