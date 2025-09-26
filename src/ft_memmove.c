#include "libft.h"
#include <stdint.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (d == s || n == 0)
		return (dest);
	
	// Check for overlap
	if (s < d && d < s + n)
	{
		// Copy backwards to avoid overlap
		s += n;
		d += n;
		
		// Optimize for large copies
		if (n >= 8)
		{
			// Align to word boundary
			while (((uintptr_t)d & (sizeof(size_t) - 1)) && n)
			{
				*(--d) = *(--s);
				n--;
			}
			
			// Copy word-sized chunks backwards
			size_t *dword = (size_t *)d;
			const size_t *sword = (const size_t *)s;
			while (n >= sizeof(size_t))
			{
				*(--dword) = *(--sword);
				n -= sizeof(size_t);
			}
			
			d = (unsigned char *)dword;
			s = (const unsigned char *)sword;
		}
		
		// Handle remaining bytes
		while (n--)
			*(--d) = *(--s);
	}
	else
	{
		// No overlap, use optimized memcpy-like approach
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
	}
	
	return (dest);
}
