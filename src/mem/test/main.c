#include <assert.h>
#include <stdio.h>
#include "ft_libft.h"

# define BUFF_SIZE 100

int	ft_test_memalloc()
{
	char	*buffer;
	int		index;

	buffer = ft_memalloc(BUFF_SIZE);
	index = 0;
	while (index < BUFF_SIZE)
	{
		assert(buffer[index] == 0);
		index++;
	}
	return (0);
}

int	ft_test_memset()
{
	char	*buffer;
	int		index;

	buffer = ft_memalloc(BUFF_SIZE);
	ft_memset(buffer, 15, BUFF_SIZE);
	index = 0;
	while (index < BUFF_SIZE)
	{
		assert(buffer[index] == 15);
		index++;
	}
	return (0);
}

int ft_test_memchr()
{
  char  buffer[] = {'a', 'b', 'c', 'd', '\0'};
  char  *ptr;

  ptr = ft_memchr(buffer, 'a', 5);
  assert(ptr && *ptr == 'a');
  ptr = ft_memchr(buffer, 'b', 5);
  assert(ptr && *ptr == 'b');
  ptr = ft_memchr(buffer, 'c', 5);
  assert(ptr && *ptr == 'c');
  ptr = ft_memchr(buffer, 'd', 5);
  assert(ptr && *ptr == 'd');
  return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	ft_test_memalloc() ? printf("ft_test_memalloc:KO\n") : printf("ft_test_memalloc:OK\n");
	ft_test_memset() ? printf("ft_test_memset:KO\n") : printf("ft_test_memset:OK\n");
  ft_test_memchr() ? printf("ft_test_memchr:KO\n") : printf("ft_test_memchr:OK\n");
	return 0;
}
