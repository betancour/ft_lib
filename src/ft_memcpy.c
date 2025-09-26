#include "libft.h"
#include <stdint.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	
	if (dest == src || n == 0)
		return (dest);
	
	// Optimize for large copies using word-sized operations
	if (n >= 8)
	{
		// Align destination to word boundary
		while (((uintptr_t)d & (sizeof(size_t) - 1)) && n)
		{
			*d++ = *s++;
			n--;
		}
		
		// Copy word-sized chunks
		size_t *dword = (size_t *)d;
		const size_t *sword = (const size_t *)s;
		while (n >= sizeof(size_t))
		{
			*dword++ = *sword++;
			n -= sizeof(size_t);
		}
		
		d = (unsigned char *)dword;
		s = (const unsigned char *)sword;
	}
	
	// Handle remaining bytes
	while (n--)
		*d++ = *s++;
	
	return (dest);
}
