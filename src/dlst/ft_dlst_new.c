#include "ft_libft.h"

int		ft_dlst_new(t_dlst **ptr)
{
	if (!(*ptr = (t_dlst *)malloc(sizeof(**ptr))))
		return (1);
	(*ptr)->len = 0;
	(*ptr)->first = 0;
	(*ptr)->last = 0;
	return (0);
}
