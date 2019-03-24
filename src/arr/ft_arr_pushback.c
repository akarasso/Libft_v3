/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:22:57 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:26:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <stdio.h>

ssize_t		ft_arr_pushback(t_arr **arr, void *newcontent)
{
	t_arr		*ptr;
	ssize_t		ret;

	if (!newcontent)
		return (-1);
	if ((*arr)->len == (*arr)->max && !ft_arr_realloc(arr, FT_ARR_REALLOC))
		return (-1);
	ptr = *arr;
	if (!ptr->len)
		ptr->first = newcontent;
	ptr->content[ptr->len] = newcontent;
	ret = ptr->len;
	ptr->last = newcontent;
	ptr->len++;
	return (ret);
}
