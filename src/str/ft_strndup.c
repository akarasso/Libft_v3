#include "ft_mem.h"
#include "ft_str.h"

char	*ft_strndup(char *s, int len)
{
	char *new;

	if (!s)
		return (0);
	if (!(new = ft_strnew(len)))
		return (0);
	ft_strncat(new, s, len);
	new[len] = 0;
	return (new);
}
