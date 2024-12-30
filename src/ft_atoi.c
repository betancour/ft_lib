#include "../include/libft.h"

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#ifndef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#endif


static int ft_isspace(char c)
{
	return (
		c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == '\v' ||
		c == '\f' ||
		c == '\r');
}

int ft_atoi(const char *nptr)
{
	size_t i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 1;

	while (ft_isspace(nptr[i]))
		i++;

	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (result > (INT_MAX - (nptr[i] - '0')) / 10)
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
