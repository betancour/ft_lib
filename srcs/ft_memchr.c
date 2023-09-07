#include "../includes/libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	c = (unsigned char)c;

	while (n && ptr != c)
	{
		++ptr;
		--n;
	}

	if (n)
		return ((void *)ptr);
	else
		return (NULL);
}
