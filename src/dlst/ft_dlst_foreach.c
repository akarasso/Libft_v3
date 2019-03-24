/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:28:14 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:28:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_dlst_foreach(t_dlst *lst, void (*func)())
{
	t_dlst_elem	*e;

	e = lst->first;
	while (e)
	{
		func(e);
		e = e->next;
	}
}
