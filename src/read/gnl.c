/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 06:56:58 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:32:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static void			ft_move(char *begin, char *end)
{
	while (*end)
	{
		*begin = *end;
		end++;
		begin++;
	}
	*begin = 0;
}

static int			buff_concat(char **line, t_cbuffer *cnl, char c)
{
	char	*pos;
	char	*new;

	pos = ft_strchr(cnl->buff, c);
	if (pos)
	{
		if ((new = ft_strnew(ft_strlen(*line) + pos - cnl->buff)))
		{
			ft_strcpy(new, *line);
			ft_strncat(new, cnl->buff, pos - cnl->buff);
			ft_move(cnl->buff, pos + 1);
		}
		ft_strdel(line);
		*line = new;
		return (1);
	}
	else
	{
		new = ft_strjoin(*line, cnl->buff);
		ft_strdel(line);
		*line = new;
		ft_strclr(cnl->buff);
		return (0);
	}
}

static t_cbuffer	*get_buffer_canal(t_cbuffer **canal, const int fd)
{
	t_cbuffer	*lst;

	lst = *canal;
	if (lst)
	{
		while (lst->next && lst->fd != fd)
			lst = lst->next;
		if (lst->fd == fd)
			return (lst);
		if (!(lst->next = (t_cbuffer*)ft_memalloc(sizeof(*lst))))
			return (0);
		lst = lst->next;
		lst->fd = fd;
	}
	else
	{
		if (!(*canal = (t_cbuffer*)ft_memalloc(sizeof(*lst))))
			return (0);
		lst = *canal;
		lst->fd = fd;
	}
	return (lst);
}

int					gnl(const int fd, char **line)
{
	static t_cbuffer	*buffs = 0;
	t_cbuffer			*cnl;
	int					ret;
	int					len;

	if (!(cnl = get_buffer_canal(&buffs, fd)))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if ((len = ft_strlen(cnl->buff)) > 0)
		if (buff_concat(line, cnl, '\n'))
			return (line) ? (1) : (-1);
	while ((ret = read(cnl->fd, cnl->buff, GNL_BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		cnl->buff[ret] = 0;
		if (buff_concat(line, cnl, '\n'))
			return (line) ? (1) : (-1);
	}
	return (line && *line && ft_strlen(*line)) ? 1 : 0;
}
