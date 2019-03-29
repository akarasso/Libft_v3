/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_token_const.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:27:09 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 14:27:10 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_regex.h"

static char		*ft_find_end_token(char *str)
{
	while (*str)
	{
		if (*str == '[' || *str == '{' || *str == '?' || *str == '*')
			return (str);
		if (*str == '\\') {
			str++;
			if (!*str)
				return (0x0);
		}
		str++;
	}
	return (0x0);
}

void			*ft_regex_pushback_range(t_dlst *tokens, char **expr)
{
	char			*end;
	t_regex_token	*new_token;

	end = ft_find_end_token(*expr);
	if (!end || !(new_token = malloc(sizeof(*new_token))))
		return (0x0);
	new_token->type = range;
	if (!(new_token->value = ft_strsub(*expr, 0, end - *expr)))
	{
		free(new_token);
		return (0x0);
	}
	ft_strunescape(new_token->value);
	*expr = end;
	return (ft_dlst_pushback(tokens, new_token));
}
