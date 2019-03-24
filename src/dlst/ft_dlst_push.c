/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:28:27 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:29:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_dlst_push(t_dlst *parent, void *child)
{
	t_dlst_elem *ptr;

	ptr = child;
	if (!child)
		return (0x0);
	if (parent->first)
	{
		parent->first->prev = ptr;
		ptr->next = parent->first;
	}
	else
		parent->last = ptr;
	parent->first = ptr;
	parent->len++;
	return (ptr);
}
