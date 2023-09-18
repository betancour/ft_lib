#include "../includes/libft.h"

char *__strrchr_chk(const char *p, int c, size_t s_len)
{
    char *save = NULL;
    while (1)
    {
        if (s_len == 0)
        {
            return NULL;
        }

        if (*p == (char)c)
            save = (char *)p;

        if (!*p)
            return save;

        p++;
        s_len--;
    }
}

char *ft_strrchr(const char *s, int c)
{
    size_t s_len = 0;
    while (s[s_len])
        s_len++;
    return __strrchr_chk(s, c, s_len);
}
