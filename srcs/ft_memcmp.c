#include "../includes/libft.h"
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)s2;
	s = (unsigned char *)s1;
	while (n && *s == *d)
	{
		++d;
		++s;
		--n;
	}
	if (n)
		return (*s - *d);
	else
		return 0;
}
