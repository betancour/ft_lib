#include "../include/libft.h"

#define INT_MIN_STR "-2147483648"

static size_t ft_get_number_length(int n)
{
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

	if (n == INT_MIN)
		return (ft_strdup(INT_MIN_STR));

	len = ft_get_number_length(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);

	i = len;
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}

	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}

	return (str);
}
