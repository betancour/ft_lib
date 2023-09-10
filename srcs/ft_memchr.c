#include "../includes/libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr = (const unsigned char *)s;
	unsigned char uc = (unsigned char)c;

    while (n > 0)
    {
        if (*ptr == uc)
            return (void *)ptr;
        ptr++;
        n--;
    }

    return NULL;
}
