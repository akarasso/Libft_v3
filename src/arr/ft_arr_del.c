/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:22:42 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:23:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_arr_del(t_arr **arr, void (*func)())
{
	size_t	index;

	index = 0;
	while (index < (*arr)->len)
	{
		func(&(*arr)->content[index]);
		index++;
	}
	free((*arr)->content);
	free(*arr);
	*arr = 0x0;
}
