/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:22:52 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:25:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

t_arr	*ft_arr_new(t_arr **arr, size_t size)
{
	if (!(*arr = malloc(sizeof(**arr))))
		return (*arr);
	if (!((*arr)->content = ft_memalloc(sizeof(void*) * (size + 1))))
	{
		free(*arr);
		return (0x0);
	}
	(*arr)->first = 0x0;
	(*arr)->last = 0x0;
	(*arr)->len = 0;
	(*arr)->max = size;
	return (*arr);
}
