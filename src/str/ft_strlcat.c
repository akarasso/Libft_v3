/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:53:55 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:14:05 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	i = dlen;
	if (size > 0)
	{
		while (*src && i < size - 1)
		{
			dest[i] = *src;
			src++;
			i++;
		}
		dest[i] = '\0';
	}
	if (size <= dlen)
		return (slen + size);
	return (dlen + slen);
}
