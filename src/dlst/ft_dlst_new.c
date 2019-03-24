/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:28:21 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:28:21 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int		ft_dlst_new(t_dlst **ptr)
{
	if (!(*ptr = (t_dlst *)malloc(sizeof(**ptr))))
		return (1);
	(*ptr)->len = 0;
	(*ptr)->first = 0;
	(*ptr)->last = 0;
	return (0);
}
