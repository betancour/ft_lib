#include "../include/libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t s_len;

	if (!s)
		return (NULL);

	s_len = ft_strlen(s);

	if (start >= s_len)
		return (ft_strdup(""));

	if (len > s_len - start)
		len = s_len - start;

	sub = (char *)malloc(sizeof(char) * (len + 1));

	if (!sub)
		return (NULL);

	ft_strlcpy(sub, s + start, len + 1);

	return (sub);
}
