/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:19:29 by akarasso          #+#    #+#             */
/*   Updated: 2019/03/24 19:36:29 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# define FT_ARR_REALLOC 3
# define LEFT 0x01
# define MID 0x02
# define RIGHT 0x04
# define GNL_BUFF_SIZE 1

typedef struct	s_cbuffer
{
	int					fd;
	char				buff[GNL_BUFF_SIZE + 1];
	struct s_cbuffer	*next;
}				t_cbuffer;

typedef struct	s_dlst_elem
{
	struct s_dlst_elem	*next;
	struct s_dlst_elem	*prev;
}				t_dlst_elem;

typedef struct	s_dlst
{
	t_dlst_elem		*first;
	t_dlst_elem		*last;
	size_t			len;
}				t_dlst;

typedef struct	s_arr
{
	void		*first;
	void		*last;
	void		**content;
	size_t		len;
	size_t		max;
}				t_arr;

/*
**  Arr
*/

t_arr			*ft_arr_new(t_arr **arr, size_t size);
t_arr			*ft_arr_realloc(t_arr **old, size_t add_amount);
ssize_t			ft_arr_pushback(t_arr **arr, void *newcontent);
t_arr			*ft_arr_join(t_arr *arr1, t_arr *arr2);
void			ft_arr_clear(t_arr *arr, void (*func)());
void			ft_arr_del(t_arr **arr, void (*func)());

/*
**	Char
*/

int				ft_is_math_op(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

/*
** Dlst
*/

void			*ft_dlst_push(t_dlst *parent, void *child);
void			*ft_dlst_pushback(t_dlst *parent, void *child);
size_t			ft_dlst_len(t_dlst *dlst);
int				ft_dlst_new(t_dlst **ptr);
void			ft_dlst_del_elem(t_dlst *parent, void *elem, void (*func)());
void			ft_dlst_del(t_dlst **parent, void (*func)());
void			ft_dlst_clear(t_dlst *parent, void (*func)());

/*
**	Integer
*/

char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				ft_nbr_len(long int n);

/*
**	IO
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** Mem
*/

void			*ft_memalloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *d1, int c, size_t n);
void			*ft_memmove(void *dest, const void *s, size_t n);
void			*ft_memcpy(void *dest, const void *s, size_t n);
void			ft_memdel(void **ap);

/*
**	Read
*/

int				gnl(const int fd, char **line);

/*
**	str
*/

char			**ft_strsplit(char const *s, char c);
char			*ft_3strjoinfree(char *s1, char *s2, char *s3, char flag);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *str, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char *s1, char *s2, char flag);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t size);
char			*ft_strndup(char *s, int len);
char			*ft_strnew(size_t n);
char			*ft_strnstr(const char *str, const char *find, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strrev(char *s);
char			*ft_strstr(const char *str, const char *find);
char			*ft_strsub(char *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *src);
int				ft_str_isvalid(char *str, char *token_chr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strdigit(char *s);
int				ft_stralpha(char *s);
void			ft_strclr(char *s);
void			ft_strdel(char **str);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strlastchr(char *s);
char			*ft_strnjoin(char *src, int lsrc, char *right, char flag);
void			ft_strrmvchr(char *s);
char			*ft_strnchr(char *str, char c, int n);
int				ft_str_onlychr(char *str, char *valid);

#endif
