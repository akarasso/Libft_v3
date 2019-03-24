/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:31:15 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:31:16 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memchr(const void *d1, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	value;

	value = (unsigned char)c;
	mem = (unsigned char *)d1;
	while (n > 0)
	{
		if (*mem == value)
			return ((void*)mem);
		mem++;
		n--;
	}
	return (0);
}
