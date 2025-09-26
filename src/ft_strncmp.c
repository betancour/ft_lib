#include "libft.h"
#include <stdint.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	
	// Optimize for large comparisons using word-sized operations
	if (n >= 8)
	{
		// Align both strings to word boundary
		while (((uintptr_t)s1 & (sizeof(size_t) - 1)) && n && *s1 && *s2)
		{
			if (*s1 != *s2)
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
			s1++;
			s2++;
			n--;
		}
		
		// Compare word-sized chunks
		const size_t *w1 = (const size_t *)s1;
		const size_t *w2 = (const size_t *)s2;
		while (n >= sizeof(size_t))
		{
			if (*w1 != *w2)
			{
				// Find the first differing byte
				const unsigned char *b1 = (const unsigned char *)w1;
				const unsigned char *b2 = (const unsigned char *)w2;
				size_t i = 0;
				while (i < sizeof(size_t))
				{
					if (b1[i] != b2[i])
						return (b1[i] - b2[i]);
					if (b1[i] == '\0')
						return (0);
					i++;
				}
			}
			else
			{
				// Check for null terminator in the word
				const unsigned char *b1 = (const unsigned char *)w1;
				size_t i = 0;
				while (i < sizeof(size_t))
				{
					if (b1[i] == '\0')
						return (0);
					i++;
				}
			}
			w1++;
			w2++;
			n -= sizeof(size_t);
		}
		
		s1 = (const char *)w1;
		s2 = (const char *)w2;
	}
	
	// Handle remaining bytes
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
