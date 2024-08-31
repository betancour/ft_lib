#include "../include/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	size_t len;
	char *ret;

	if (!s1 || !s2)
		return (NULL);

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	if (s1_len > SIZE_MAX - s2_len - 1)
		return (NULL);

	len = s1_len + s2_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));

	if (!ret)
		return (NULL);

	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len + 1);
	ret[len] = '\0';

	return (ret);
}
