#include "ft_libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;
	if (!(ptr = malloc(size)))
		return (0x0);
	ft_memset(ptr, 0, size);
	return (ptr);
}
