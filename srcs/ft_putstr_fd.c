#include "libft.h"

static size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (*(str + 1))
		i++;
	return (i);
}

void ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}
