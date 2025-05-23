#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (count != 0 && size >= SIZE_MAX / count)
		return (NULL);

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);

	ft_bzero(ptr, count * size);

	return (ptr);
}
