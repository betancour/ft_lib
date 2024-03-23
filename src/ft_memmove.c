#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (d == s)
		return dest;
	if (s < d && d < s + n)
	{
		s += n;
		d += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return dest;
}
