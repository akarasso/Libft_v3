#include "ft_str.h"

char	*ft_strnchr(char *str, char c, int n)
{
	while (*str && n > 0)
	{
		if (*str == c)
			return ((char*)str);
		n--;
		str++;
	}
	return (0);
}
