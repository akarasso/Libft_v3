#include "ft_libft.h"

/*
** NB: Un jour, il faudra changer pour une vrai solution avec realloc...
**  Dans 30ans.. (jamais)
*/

t_arr   *ft_arr_realloc(t_arr **old, size_t add_amount)
{
	t_arr *new;

	if (!ft_arr_new(&new, (*old)->max + add_amount))
		return (0x0);
	ft_memmove(new->content, (*old)->content, sizeof(void*) * (*old)->len);
	new->max = (*old)->max + add_amount;
	new->len = (*old)->len;
	new->first = (*old)->first;
	new->last = (*old)->last;
	free((*old)->content);
	free(*old);
	*old = new;
	return (new);
}
