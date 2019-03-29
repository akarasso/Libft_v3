/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_token_quantify.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:27:13 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 14:27:14 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_libft.h"

static int	*check_curly_content(char *content)
{
	char	number;
	char	comma;

	number = 0;
	comma = 0;
	while (*content)
	{
		if (content >= '0' || content <= '9')
			number = 1;
		else if (content == ',')
		{
			if (!number || comma)
				return (1);
			comma = 1;
		}
		else
			return (1);
	}
	return (0);
}

void		*ft_regex_pushback_curly(t_dlst *tokens, char **expr)
{
	char			*end;
	t_regex_token	*new_token;

	end = ft_find_end_token(*expr, '}');
	if (!end || !(new_token = malloc(sizeof(*new_token))))
		return (0x0);
	new_token->type = range;
	if (!(new_token->value = ft_strsub(*expr, 1, end - *expr - 1)))
	{
		free(new_token);
		return (0x0);
	}
	*expr = end;
	return ft_dlst_pushback(tokens, new_token);
}

void		*ft_regex_pushback_question(t_dlst *tokens, char **expr)
{
	t_regex_token	*new_token;

	if (!(new_token = malloc(sizeof(*new_token))))
		return (0x0);
	new_token->type = QUESTION;
	(*expr)++;
	return (ft_dlst_pushback(tokens, new_token));
}

void		*ft_regex_pushback_star(t_dlst *tokens, char **expr)
{
	t_regex_token	*new_token;

	if (!(new_token = malloc(sizeof(*new_token))))
		return (0x0);
	new_token->type = STAR;
	(*expr)++;
	return (ft_dlst_pushback(tokens, new_token));
}
