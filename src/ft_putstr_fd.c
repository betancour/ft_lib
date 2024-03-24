#include "libft.h"
#include <unistd.h>

char *ft_putstr_fd(char *s, int fd)
{
    if (s)
    {
        write(fd, s, ft_strlen(s));
        return s;
    }
    return NULL;
}

