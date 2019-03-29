/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunescape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:17:42 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 14:20:27 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_strunescape(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		if (*str == '\\')
			*str++;
		*ptr = str;
		ptr++;
		str++;
	}
	*ptr = 0;
}
