/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:50:27 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:46:10 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memcpy(void *dest, const void *s, size_t n)
{
	char	*ptr;
	char	*src;
	size_t	i;

	src = (char*)s;
	ptr = (char*)dest;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = *(src + i);
		i++;
	}
	return (dest);
}
