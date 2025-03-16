#include "libft.h"


char *ft_strrchr(const char *s, int c)
{
	char *last_occurrence = NULL;

	while(*s)
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;

	return last_occurrence;

}
