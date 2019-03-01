#include "ft_libft.h"

void 	*ft_dlst_push(t_dlst *parent, void *child)
{
	t_dlst_elem *ptr;
	t_dlst_elem *last;

	ptr = child;
	if (!child)
		return (0x0);
	if (parent->first)
	{
		parent->first->prev = ptr;
		ptr->next = parent->first;
	}
	else
		parent->last = ptr;
	parent->first = ptr;
	parent->len++;
	return (ptr);
}
