#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ft_libft.h"
typedef struct	s_elem_test
{
	struct s_elem_test	*next;
	struct s_elem_test	*prev;
	char				*s;
}				t_elem_test;

static char		*tests[] = {"Chaine1", "Chaine2", "Chaine3", 0x0};

t_elem_test *create_elem(char *s)
{
	t_elem_test *new;

	if (!(new = malloc(sizeof(*new))))
		return 0x0;
	new->prev = 0;
	new->next = 0;
	new->s = strdup(s);
	return (new);
}

void 		free_elem(t_elem_test *ptr)
{
	free(ptr->s);
	free(ptr);
}

int		ft_test_clear(t_dlst *list)
{
	ft_dlst_clear(list, free_elem);
	if (list->len != 0)
	{
		printf("Bad len\n");
		return (1);
	}
	if (list->first || list->last)
	{
		printf("First or last still define\n");
		return (1);
	}
	return (0);
}

int 	ft_test_push(t_dlst *list)
{

	char		 	**ptr;
	t_elem_test		*elem;
	t_elem_test		*old_elem;
	size_t			index;

	ptr = tests;
	old_elem = 0x0;
	index = 0;
	while (*ptr)
	{
		index++;
		elem = ft_dlst_push(list, create_elem(*ptr));
		assert(elem->next == old_elem);
		assert(index == list->len);
		old_elem = elem;
		printf("Len dlst: %lu Elem: .value '%s' .address:%p .next:%p\n", list->len, elem->s, elem, elem->next);
		ptr++;
	}
	return (0);
}

int 	ft_test_pushback(t_dlst *list)
{

	char		 	**ptr;
	t_elem_test		*elem;
	t_elem_test		*old_elem;
	size_t			index;

	ptr = tests;
	old_elem = 0x0;
	index = 0;
	while (*ptr)
	{
		index++;
		elem = ft_dlst_pushback(list, create_elem(*ptr));
		assert(elem->prev == old_elem);
		assert(index == list->len);
		old_elem = elem;
		printf("Len dlst: %lu Elem: .value '%s' .address:%p .prev:%p\n", list->len, elem->s, elem, elem->prev);
		ptr++;
	}
	return (0);
}

int 	ft_test_del_elem(t_dlst *list)
{
	t_elem_test		*elemfirst, *elemmiddle, *elemlast;
	size_t			index;


	elemfirst = ft_dlst_pushback(list, create_elem(tests[0]));
	elemmiddle = ft_dlst_pushback(list, create_elem(tests[1]));
	elemlast = ft_dlst_pushback(list, create_elem(tests[2]));
	ft_dlst_del_elem(list, elemfirst, free_elem);
	assert(list->len == 2);
	assert(list->first == (t_dlst_elem*)elemmiddle);
	elemfirst = ft_dlst_push(list, create_elem(tests[0]));
	assert(list->len == 3);
	assert(list->first == (t_dlst_elem*)elemfirst);
	ft_dlst_del_elem(list, elemlast, free_elem);
	assert(list->len == 2);
	assert(list->last == (t_dlst_elem*)elemmiddle);
	ft_dlst_del_elem(list, elemmiddle, free_elem);
	assert(list->len == 1);
	assert(list->last == (t_dlst_elem*)elemfirst);
	assert(list->first == (t_dlst_elem*)elemfirst);
	ft_dlst_del_elem(list, elemfirst, free_elem);
	assert(list->len == 0);
	assert(list->last == 0x0);
	assert(list->first == 0x0);
	return (0);
}

int	ft_test_del(t_dlst *list)
{
	ft_dlst_del(&list, free_elem);
	assert(list == 0x0);
}

int main(int argc, char **argv)
{
	t_dlst *list;

	list = 0x0;
	printf("Start test on dlst\n");
	if (!ft_dlst_new(&list))
	{
		printf("ft_dlst_new:OK\n");
		ft_test_push(list) ? printf("ft_test_push:KO\n") : printf("ft_test_push:OK\n");
		ft_test_clear(list) ? printf("ft_test_clear:KO\n") : printf("ft_test_clear:OK\n");
		ft_test_pushback(list) ? printf("ft_test_pushback:KO\n") : printf("ft_test_pushback:OK\n");
		ft_test_clear(list);
		ft_test_del_elem(list) ? printf("ft_test_del_elem:KO\n") : printf("ft_test_del_elem:OK\n");
		ft_test_del(list) ? printf("ft_test_del:KO\n") : printf("ft_test_del:OK\n");
	}
	else printf("ft_dlst_new:KO\n");
	return (0);
}
