/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:31:19 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:31:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_memcmp(const void *d1, const void *d2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char*)d1;
	s2 = (const unsigned char*)d2;
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
