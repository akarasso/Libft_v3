#include "ft_libft.h"

void 	*ft_dlst_pushback(t_dlst *parent, void *child)
{
	t_dlst_elem *ptr;
	t_dlst_elem *last;

	ptr = child;
	if (!child)
		return (0x0);
	if (parent->last)
	{
		parent->last->next = ptr;
		ptr->prev = parent->last;
	}
	else
		parent->first = ptr;
	parent->last = ptr;
	parent->len++;
	return (ptr);
}
