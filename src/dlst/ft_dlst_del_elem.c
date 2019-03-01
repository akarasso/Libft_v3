#include "ft_libft.h"

void ft_dlst_del_elem(t_dlst *parent, void *elem, void (*func)())
{
	t_dlst_elem *ptr;

	ptr = elem;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	if (ptr == parent->first)
		parent->first = parent->first->next;
	if (ptr == parent->last)
		parent->last = parent->last->prev;
	func((void*)ptr);
	parent->len--;
}
