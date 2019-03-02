/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:37 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/03 17:55:38 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *last;

	last = 0;
	while (*str)
	{
		if (*str == c)
			last = (char*)str;
		str++;
	}
	if (c == 0)
		return ((char*)str);
	return (last);
}
