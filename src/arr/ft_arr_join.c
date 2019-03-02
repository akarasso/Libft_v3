#include "ft_libft.h"

static void		ft_arr_del_parent(t_arr *arr)
{
	free(arr->content);
	free(arr);
}

static t_arr	*ft_arr_newjoin(t_arr *arr1, t_arr *arr2)
{
	t_arr	*new;

	ft_arr_new(&new, arr2->len + arr1->len);
	ft_memmove(new->content, arr1->content, arr1->len * sizeof(void*));
	ft_memmove(&new->content[arr1->len],
		arr2->content, arr2->len * sizeof(void*));
	new->len = arr1->len + arr2->len;
	ft_arr_del_parent(arr1);
	ft_arr_del_parent(arr2);
	return (new);
}

t_arr			*ft_arr_join(t_arr *arr1, t_arr *arr2)
{
	if (arr1->len + arr2->len <= arr1->max)
	{
		ft_memmove(&arr1->content[arr1->len],
			arr2->content, arr2->len * sizeof(void*));
		arr1->len = arr1->len + arr2->len;
		ft_arr_del_parent(arr2);
		return (arr1);
	}
	else if (arr1->len + arr2->len <= arr2->max)
	{
		ft_memmove(&arr2->content[arr1->len],
			arr2->content, arr2->len * sizeof(void*));
		ft_memmove(arr2->content, arr1->content, arr1->len * sizeof(void*));
		arr2->len = arr1->len + arr2->len;
		ft_arr_del_parent(arr1);
		return (arr2);
	}
	else
		return ft_arr_newjoin(arr1, arr2);
}
