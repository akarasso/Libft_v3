/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:22:38 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:24:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_arr_del_elem(t_arr *arr, size_t index, void (*func)())
{
	if (index < arr->len)
	{
		func(&arr->content[index]);
		arr->len--;
		while (index < arr->len)
		{
			arr->content[index] = arr->content[index + 1];
			index++;
		}
	}
}
