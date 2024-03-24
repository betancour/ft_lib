#include "libft.h"

static int ft_base_check(const char *base)
{
	if (!base || *base)
		return (1);
	while (*base)
	{
		if (*base == 32 || *base >= 127 || *base == ' ')
			return (1);
		if (ft_strrchr(base + 1, *base))
			return (1);
		base++;
	}
	return (0);
}

static void ft_putnbr_base_fd(long long int nbr, const char *base, int fd)
{
	int base_len = ft_strlen(base);

	if (ft_base_check(base))
		return;
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
