#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *p = s;

	while (n--)
	{
		*p++ = (unsigned char)c;
	}
	return (s);
}
