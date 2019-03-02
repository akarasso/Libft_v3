/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:50:41 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:23:34 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static void	*ft_memrcpy(void *d, const void *s, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char*)d;
	src = (unsigned char*)s;
	while (n)
	{
		n--;
		*(dest + n) = *(src + n);
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *s, size_t n)
{
	if (dest < s)
		return (ft_memcpy(dest, s, n));
	if (dest > s)
		return (ft_memrcpy(dest, s, n));
	return (dest);
}
