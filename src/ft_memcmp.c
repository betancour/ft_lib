#include "libft.h"
#include <stdint.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ss1 = (const unsigned char *)s1;
	const unsigned char *ss2 = (const unsigned char *)s2;
	
	if (n == 0)
		return (0);
	
	// Optimize for large comparisons using word-sized operations
	if (n >= 8)
	{
		// Align both pointers to word boundary
		while (((uintptr_t)ss1 & (sizeof(size_t) - 1)) && n)
		{
			if (*ss1 != *ss2)
				return (*ss1 - *ss2);
			ss1++;
			ss2++;
			n--;
		}
		
		// Compare word-sized chunks
		const size_t *w1 = (const size_t *)ss1;
		const size_t *w2 = (const size_t *)ss2;
		while (n >= sizeof(size_t))
		{
			if (*w1 != *w2)
			{
				// Find the first differing byte
				const unsigned char *b1 = (const unsigned char *)w1;
				const unsigned char *b2 = (const unsigned char *)w2;
				size_t i = 0;
				while (i < sizeof(size_t) && i < n)
				{
					if (b1[i] != b2[i])
						return (b1[i] - b2[i]);
					i++;
				}
			}
			w1++;
			w2++;
			n -= sizeof(size_t);
		}
		
		ss1 = (const unsigned char *)w1;
		ss2 = (const unsigned char *)w2;
	}
	
	// Handle remaining bytes
	while (n--)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	
	return (0);
}
