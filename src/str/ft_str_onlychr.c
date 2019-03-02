#include "ft_str.h"

int		ft_str_onlychr(char *str, char *valid)
{
	while (*str)
	{
		if (!ft_strchr(valid, *str))
			return (0);
		str++;
	}
	return (1);
}
