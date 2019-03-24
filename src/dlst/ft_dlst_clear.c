/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:27:57 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:27:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_dlst_clear(t_dlst *parent, void (*func)())
{
	t_dlst_elem *ptr;
	t_dlst_elem *next;

	if (parent)
	{
		ptr = parent->first;
		while (ptr)
		{
			next = ptr->next;
			func((void*)ptr);
			ptr = next;
		}
		parent->len = 0;
		parent->first = 0x0;
		parent->last = 0x0;
	}
}
