/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_token_operator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:26:19 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 15:26:47 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_libft.h"

void		*ft_regex_pushback_aler(t_dlst *tokens, char **expr)
{
	t_regex_token	*new_token;

	if (!(new_token = malloc(sizeof(*new_token))))
		return (0x0);
	new_token->type = REGEX_SUB;
	if (!(new_token->value = ft_strsub(*expr, 1, 1)))
	{
		free(new_token);
		return (0x0);
	}
	(*expr)++;
	return ft_dlst_pushback(tokens, new_token);
}

void		*ft_regex_pushback_aler(t_dlst *tokens, char **expr)
{
	char			*end;
	t_regex_token	*new_token;

	if (!(new_token = malloc(sizeof(*new_token))))
		return (0x0);
	new_token->type = REGEX_ALTER;
	if (!(new_token->value = ft_strsub(*expr, 1, 1)))
	{
		free(new_token);
		return (0x0);
	}
	(*expr)++;
	return ft_dlst_pushback(tokens, new_token);
}
