#include "ft_char.h"

int		ft_stralpha(char *s)
{
	while (*s && ft_isalpha(*s))
		s++;
	return (*s) ? 0 : 1;
}