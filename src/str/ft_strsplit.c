/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:46 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/05 14:54:13 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_str.h"

static int	ft_count_word(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static int	ft_size_word(char const *s, char c)
{
	int size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		index;
	int		size;

	index = 0;
	if (!s || !(ret = (char**)malloc((ft_count_word(s, c) + 1) * sizeof(*ret))))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			size = ft_size_word(s, c);
			if (!(ret[index] = (char*)ft_memalloc(size + 1)))
				return (0);
			ret[index] = ft_strncpy(ret[index], s, size);
			ret[index][size] = '\0';
			index++;
			s += size;
		}
		else
			s++;
	}
	ret[index] = NULL;
	return (ret);
}
