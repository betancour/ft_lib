#include "libft.h"

static size_t str_len(char *str)
{
	size_t i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, str_len(s));
		write(fd, "\n", 1);
	}
}
