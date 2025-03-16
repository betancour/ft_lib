#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len = 0;

	while (src[src_len] != '\0')
		src_len++;

	if (size == 0)
		return (src_len);

	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}

	if (size > 0)
		*dst = '\0';

	return (src_len);
}
