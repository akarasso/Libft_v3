/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:28:11 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 16:29:40 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_libft.h"

int		ft_regex_parser(t_dlst *tokens)
{
	t_regex_token	*token;
	int				operator_state;
	int				quantifier_state;
	int				word_state;

	token = tokens->first;
	while (token)
	{

		token = token->next;
	}
}
