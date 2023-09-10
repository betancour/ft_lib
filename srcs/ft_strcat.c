#include "../includes/libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	const char *odst = dst;
	const char *osrc = src;

	size_t n = size;
	size_t dlen;

	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = size - dlen;

	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src++;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
