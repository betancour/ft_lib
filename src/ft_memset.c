#include "libft.h"
#include <stdint.h>

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *p = (unsigned char *)s;
	unsigned char byte = (unsigned char)c;
	
	if (n == 0)
		return (s);
	
	// Optimize for large fills using word-sized operations
	if (n >= 8)
	{
		// Align destination to word boundary
		while (((uintptr_t)p & (sizeof(size_t) - 1)) && n)
		{
			*p++ = byte;
			n--;
		}
		
		// Fill word-sized chunks
		size_t word = 0;
		size_t i;
		for (i = 0; i < sizeof(size_t); i++)
		{
			word |= ((size_t)byte << (i * 8));
		}
		
		size_t *pword = (size_t *)p;
		while (n >= sizeof(size_t))
		{
			*pword++ = word;
			n -= sizeof(size_t);
		}
		
		p = (unsigned char *)pword;
	}
	
	// Handle remaining bytes
	while (n--)
		*p++ = byte;
	
	return (s);
}
