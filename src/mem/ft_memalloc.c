/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:31:06 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:31:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(ptr = malloc(size)))
		return (0x0);
	ft_memset(ptr, 0, size);
	return (ptr);
}
