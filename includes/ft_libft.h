#ifndef FT_LILBFT_H
# define FT_LILBFT_H

# include <stddef.h>
# include <stdlib.h>

# define FT_ARR_REALLOC 3

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
  void			*first;
  void			*last;
  void			**content;
  size_t		len;
  size_t		max;
}				t_arr;

/*
** Dlst
*/

void 			*ft_dlst_push(t_dlst *parent, void *child);
void 			*ft_dlst_pushback(t_dlst *parent, void *child);
size_t			ft_dlst_len(t_dlst *dlst);
int				ft_dlst_new(t_dlst **ptr);
void			ft_dlst_del_elem(t_dlst *parent, void *elem, void (*func)());
void			ft_dlst_del(t_dlst **parent, void (*func)());
void			ft_dlst_clear(t_dlst *parent, void (*func)());

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
**  Arr
*/

t_arr			*ft_arr_new(t_arr **arr, size_t size);
t_arr			*ft_arr_realloc(t_arr **old, size_t add_amount);
ssize_t			ft_arr_pushback(t_arr **arr, void *newcontent);
t_arr			*ft_arr_join(t_arr *arr1, t_arr *arr2);
void			ft_arr_clear(t_arr *arr, void (*func)());
void			ft_arr_del(t_arr **arr, void (*func)());


#endif
