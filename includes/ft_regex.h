/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a.karass <a.karass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:34:28 by a.karass          #+#    #+#             */
/*   Updated: 2019/03/29 14:12:21 by a.karassouloff   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEX_H
# define FT_REGEX_H

#define RANGE 0
#define STAR 0
#define LIST 0
#define QUESTION 0

typedef struct	s_regex_token
{
	t_regex_token		*next;
	t_regex_token		*prev;
	char				*value;
	int					type;
}				t_regex_token;



#endif
