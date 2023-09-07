#include "../includes/libft.h"
char *
__strchr_chk(const char *p, int c, size_t len)
{
	while (1)
	{
		if (len == 0)
			__fortify_chk_fail("strchr read beyond buffer", 0);
		if (*p == (char)c)
			return (char *)p;
		if (!*p)
			return (char *)NULL;
		p++;
		len--;
	}
	/* NOTREACHED */
}

char *
ft_strchr(const char *s, int c)
{
	size_t len = 0;
	while (s[len])
		len++;

	return __strchr_chk(s, c, len);
}
