#include "libft.h"

char *ft_strdup(const char *src)
{
	size_t len;
	char *new;
	
	len = ft_strlen(src);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	
	ft_memcpy(new, src, len + 1);
	return (new);
}
