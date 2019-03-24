/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:35:14 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:35:14 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strndup(char *s, int len)
{
	char *new;

	if (!s)
		return (0);
	if (!(new = ft_strnew(len)))
		return (0);
	ft_strncat(new, s, len);
	new[len] = 0;
	return (new);
}
