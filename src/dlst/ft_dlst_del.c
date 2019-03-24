/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:28:10 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:28:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_dlst_del(t_dlst **parent, void (*func)())
{
	t_dlst_elem *ptr;
	t_dlst_elem *next;

	if (parent)
	{
		ptr = (*parent)->first;
		while (ptr)
		{
			next = ptr->next;
			func((void*)ptr);
			ptr = next;
		}
		free(*parent);
		*parent = 0x0;
	}
}
