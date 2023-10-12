#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;

	if (!s || !f)
		return (NULL);

	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));

	if (!result)
		return (NULL);

	for (unsigned int i = 0; i < len; i++)
		result[i] = f(i, s[i]);

	result[len] = '\0';

	return (result);
}
