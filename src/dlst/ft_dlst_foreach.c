#include "ft_libft.h"

void	ft_dlst_foreach(t_dlst *lst, void (*func)())
{
  t_dlst_elem *e;

  e = lst->first;
  while (e)
  {
    func(e);
    e = e->next;
  }
}
