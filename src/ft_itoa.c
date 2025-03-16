#include "libft.h"

#define INT_MIN_STR "-2147483648"

static size_t ft_get_number_length(int n)
{
    if (n == INT_MIN)
        return (11);
	size_t len;

	len = (n == 0) ? 1 : 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *str;
	size_t len;
	size_t i;
	unsigned int num;

	if (n == INT_MIN)
		return (ft_strdup(INT_MIN_STR));

	len = ft_get_number_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	str[len] = '\0';
	num = (n < 0) ? -n : n;
	i = len - 1;
	if (n == 0)
		str[0] = '0';
	else
	{
		while (num > 0)
		{
			str[i] = (num % 10) + '0';
			num /= 10;
			i--;
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
