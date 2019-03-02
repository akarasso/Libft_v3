/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:49:42 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/27 06:32:25 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "ft_mem.h"
#include "ft_str.h"

static int	ft_int_len(long int n)
{
	int len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	size_t	nbr;
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_int_len(n);
	nbr = (n < 0) ? -n : n;
	if (!(ret = (char*)malloc(len + 1)))
		return (0);
	ret[len] = '\0';
	len--;
	while (len > -1)
	{
		ret[len] = '0' + (nbr % 10);
		nbr /= 10;
		len--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
