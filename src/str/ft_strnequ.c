/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:14 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:15:26 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && !ft_strncmp(s1, s2, n))
		return (1);
	return (0);
}