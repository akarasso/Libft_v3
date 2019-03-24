/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_onlychr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:33:22 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:33:22 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int		ft_str_onlychr(char *str, char *valid)
{
	while (*str)
	{
		if (!ft_strchr(valid, *str))
			return (0);
		str++;
	}
	return (1);
}
