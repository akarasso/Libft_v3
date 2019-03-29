#include "ft_regex.h"

t_regex		*ft_regex_comp(char *expr)
{
	t_regex		*regex;
	t_dlst 		*tokens;

	if (!(tokens = ft_regex_tokenise(expr)))
		return (0x0);
	return (regex);
}
