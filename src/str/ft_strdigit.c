#include "ft_char.h"

int		ft_strdigit(char *s)
{
	while (*s && ft_isdigit(*s))
		s++;
	return (*s) ? 0 : 1;
}