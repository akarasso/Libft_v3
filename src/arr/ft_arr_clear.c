/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:22:35 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:22:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_arr_clear(t_arr *arr, void (*func)())
{
	size_t	curr;

	curr = 0;
	while (curr < arr->len)
	{
		func(&arr->content[curr]);
		curr++;
	}
	arr->first = 0x0;
	arr->last = 0x0;
	arr->len = 0;
}
