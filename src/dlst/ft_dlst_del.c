#include "ft_libft.h"

void ft_dlst_del(t_dlst **parent, void (*func)())
{
	t_dlst_elem *ptr;
	t_dlst_elem *next;

	if (parent)
	{
		ptr = (*parent)->first;
		while (ptr)
		{
			next = ptr->next;
			func((void*)ptr);
			ptr = ptr->next;
		}
		free(*parent);
		*parent = 0x0;
	}
}
