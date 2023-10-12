#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);

	start = 0;
	while (s1[start] && is_whitespace(s1[start]) && ft_strchr(set, s1[start]))
		start++;

	end = ft_strlen(s1);
	while (end > start && is_whitespace(s1[end - 1]) && ft_strchr(set, s1[end - 1]))
		end--;

	if (start >= end)
		return (ft_strdup(""));

	return (ft_substr(s1, start, end - start));
}
