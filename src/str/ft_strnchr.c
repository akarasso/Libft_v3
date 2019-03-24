/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:35:08 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:35:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strnchr(char *str, char c, int n)
{
	while (*str && n > 0)
	{
		if (*str == c)
			return ((char*)str);
		n--;
		str++;
	}
	return (0);
}
