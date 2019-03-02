/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:46 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:45:28 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *d;

	d = dest;
	while (*d)
		d++;
	while (*src && n > 0)
	{
		*d = *src;
		d++;
		src++;
		n--;
	}
	*d = '\0';
	return (dest);
}
