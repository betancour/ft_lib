#include "libft.h"

static int ft_base_check(const char *base)
{
	int i;
	int j;

	if (!base || ft_strlen(base) < 2)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] <= 32 || base[i] >= 127)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void ft_putnbr_base_fd(long long int nbr, const char *base, int fd)
{
	int base_len;

	if (ft_base_check(base) || fd < 0)
		return;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr < base_len)
		ft_putchar_fd(base[nbr], fd);
	else
	{
		ft_putnbr_base_fd(nbr / base_len, base, fd);
		ft_putnbr_base_fd(nbr % base_len, base, fd);
	}
}

void ft_putnbr_fd(int n, int fd)
{
	char const *base = "0123456789";

	if (n == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putnbr_base_fd((long long int)n, base, fd);
}
