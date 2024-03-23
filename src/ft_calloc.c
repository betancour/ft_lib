#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}

	if (!(ptr == malloc(count * size)))
		return (NULL);

	ft_bzero(ptr, count * size);

	return (ptr);
}
