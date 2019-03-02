#include "ft_libft.h"
#include <stdio.h>

ssize_t ft_arr_pushback(t_arr **arr, void *newcontent)
{
	t_arr		*ptr;
	ssize_t		ret;

	if (!newcontent)
		return (-1);
	if ((*arr)->len == (*arr)->max && !ft_arr_realloc(arr, FT_ARR_REALLOC))
		return (-1);
	ptr = *arr;
	if (!ptr->len)
		ptr->first = newcontent;
	ptr->content[ptr->len] = newcontent;
	ret = ptr->len;
	ptr->last = newcontent;
	ptr->len++;
	return (ret);
}
