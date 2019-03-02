/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:56:27 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:17:09 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_char.h"
#include "ft_str.h"

static int	is_space(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

static char	*first_non_space(char *str)
{
	while (*str)
	{
		if (!is_space(*str))
			return (str);
		str++;
	}
	return (str);
}

static char	*last_non_space(char *str)
{
	char *s;

	s = str;
	while (*str)
	{
		if (!is_space(*str))
			s = str;
		str++;
	}
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char *new;
	char *start;
	char *end;

	if (!s)
		return (0);
	start = first_non_space((char*)s);
	end = last_non_space(start);
	if (start == end)
		return (ft_strdup(""));
	new = (char*)ft_memalloc(end - start + 2);
	if (!new)
		return (0);
	new = ft_strncpy(new, start, end - start + 1);
	new[end - start + 1] = 0;
	return (new);
}
