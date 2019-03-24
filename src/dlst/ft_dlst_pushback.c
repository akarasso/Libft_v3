/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:28:31 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:29:50 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_dlst_pushback(t_dlst *parent, void *child)
{
	t_dlst_elem *ptr;

	ptr = child;
	if (!child)
		return (0x0);
	if (parent->last)
	{
		parent->last->next = ptr;
		ptr->prev = parent->last;
	}
	else
		parent->first = ptr;
	parent->last = ptr;
	parent->len++;
	return (ptr);
}
