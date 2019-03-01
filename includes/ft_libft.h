#ifndef FT_LILBFT_H
# define FT_LILBFT_H

# include <stddef.h>
# include <stdlib.h>

typedef struct	s_dlst_elem
{
	struct s_dlst_elem	*next;
	struct s_dlst_elem	*prev;
}				t_dlst_elem;

typedef struct	s_dlst
{
	size_t				len;
	t_dlst_elem			*first;
	t_dlst_elem			*last;
}				t_dlst;

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

#endif
