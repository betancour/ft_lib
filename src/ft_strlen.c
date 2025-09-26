#include "libft.h"
#include <stdint.h>

size_t ft_strlen(const char *s)
{
	const char *start = s;
	
	// Align to word boundary
	while (((uintptr_t)s & (sizeof(size_t) - 1)) && *s)
		s++;
	
	if (*s == '\0')
		return (s - start);
	
	// Check word-sized chunks for null terminator
	const size_t *w = (const size_t *)s;
	while (1)
	{
		size_t word = *w;
		
		// Check each byte in the word for null terminator
		if ((word - 0x0101010101010101UL) & ~word & 0x8080808080808080UL)
		{
			// Found a null terminator, find exact position
			const char *c = (const char *)w;
			while (*c)
				c++;
			return (c - start);
		}
		w++;
	}
}
