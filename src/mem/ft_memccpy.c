#include "ft_libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char *schar;
	unsigned char x;

	schar = (unsigned char*)src;
	ptr = (unsigned char*)dest;
	x = (unsigned char)c;
	while (n > 0)
	{
		*ptr = *schar;
		if (*schar == x)
			return (ptr + 1);
		schar++;
		ptr++;
		n--;
	}
	return (NULL);
}
