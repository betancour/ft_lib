#include "libft.h"

char *ft_strdup(char *src)
{
	char *new;
	int i;
	int size;

	ise = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size))))
		return NULL;
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return new;
}
