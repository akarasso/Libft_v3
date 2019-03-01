#include "ft_libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *ptr;

	ptr = (char*)s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
