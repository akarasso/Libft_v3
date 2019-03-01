#include "ft_libft.h"

void ft_dlst_clear(t_dlst *parent, void (*func)())
{
	t_dlst_elem *ptr;
	t_dlst_elem *next;

	if (parent)
	{
		ptr = parent->first;
		while (ptr)
		{
			next = ptr->next;
			func((void*)ptr);
			ptr = next;
		}
		parent->len = 0;
		parent->first = 0x0;
		parent->last = 0x0;
	}
}
