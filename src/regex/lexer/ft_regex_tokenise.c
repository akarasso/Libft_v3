/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_tokenise.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:27:01 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 15:23:40 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_libft.h"

void			ft_regex_tokenise_error(t_regex_token *tokens)
{
	free(tokens->value);
	free(tokens);
}

void			*ft_regex_pushback_quantifier(t_dlst *tokens, char **expr)
{
	void	*new_token;

	if (**expr == '?')
		new_token = ft_regex_pushback_question(tokens, expr);
	else if (**expr == '*')
		new_token = ft_regex_pushback_star(tokens, expr);
	else if (**expr == '{')
		new_token = ft_regex_pushback_curly(tokens, expr);
	else
		new_token = 0x0;
	return (new_token);
}

void			*ft_regex_pushback_operator(t_dlst *tokens, char **expr)
{
	void	*new_token;

	if (**expr == '(')
		new_token = ft_regex_pushback_sub(tokens, expr);
	else if (**expr == '|')
		new_token = ft_regex_pushback_alter(tokens, expr);
	else
		new_token = 0x0;
	return (new_token);
}

t_dlst			*ft_regex_tokenise(char *expr)
{
	t_dlst	*tokens;
	void	*new_token;

	if (!expr || ft_dlst_new(&tokens))
		return (0x0);
	while (*expr)
	{
		if (*expr == '*' || *expr == '{' || *expr == '?')
			new_token = ft_regex_pushback_quantifier(tokens, &expr);
		else if (*expr == '(' || *expr == '|')
			new_token = ft_regex_pushback_operator(tokens, &expr);
		else if (expr == '[')
			new_token = ft_regex_pushback_range(tokens, &expr);
		else
			new_token = ft_regex_pushback_const(tokens, &expr);
		if (!new_token)
		{
			ft_dlst_del(&token, ft_regex_tokenise_error);
			ft_regex_tokenise_error(tokens);
			return (0x0);
		}
	}
}
