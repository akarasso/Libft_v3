/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:31:10 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:31:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char *schar;
	unsigned char x;

	schar = (unsigned char*)src;
	ptr = (unsigned char*)dest;
	x = (unsigned char)c;
	while (n > 0)
	{
		*ptr = *schar;
		if (*schar == x)
			return (ptr + 1);
		schar++;
		ptr++;
		n--;
	}
	return (NULL);
}
