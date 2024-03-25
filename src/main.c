#include "libft.h"

int main(void)
{
	void test_ft_atoi(void)
	{
		int i = ft_atoi("  -+--+--+1234ab567");
		printf("ft_atoi: %d\n", i);
	}
	test_ft_atoi();
	system("leaks a.out");
	return (0);
}
