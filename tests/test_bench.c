/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bench.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

# define BENCH_ITERS	200000
# define BENCH_BUF		4096

static void	print_bench(const char *name, double ft_ms, double libc_ms)
{
	double	ratio;

	ratio = (libc_ms > 0.0) ? (ft_ms / libc_ms) : 0.0;
	printf("  %-12s  ft: %8.3f ms   libc: %8.3f ms   ratio: %6.2fx",
		name, ft_ms, libc_ms, ratio);
	if (ratio <= 1.5)
		printf(C_GREEN "  (good)" C_RESET "\n");
	else if (ratio <= 5.0)
		printf(C_YELLOW "  (slower)" C_RESET "\n");
	else
		printf(C_RED "  (much slower)" C_RESET "\n");
}

static void	bench_strlen(void)
{
	const char	*s;
	volatile size_t	sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	s = "The quick brown fox jumps over the lazy dog. "
		"Pack my box with five dozen liquor jugs. 0123456789";
	sink = 0;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 10)
	{
		sink += ft_strlen(s);
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 10)
	{
		sink += strlen(s);
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("strlen", ft_ms, lc_ms);
	(void)sink;
}

static void	bench_memset(void)
{
	char		buf[BENCH_BUF];
	volatile unsigned char	*p;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	p = (volatile unsigned char *)buf;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		ft_memset(buf, (unsigned char)i, BENCH_BUF);
		p[0] = p[0];
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		memset(buf, (unsigned char)i, BENCH_BUF);
		p[0] = p[0];
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("memset", ft_ms, lc_ms);
}

static void	bench_memcpy(void)
{
	char		src[BENCH_BUF];
	char		dst[BENCH_BUF];
	volatile unsigned char	*p;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	memset(src, 'A', sizeof(src));
	p = (volatile unsigned char *)dst;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		ft_memcpy(dst, src, BENCH_BUF);
		p[0] = p[0];
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		memcpy(dst, src, BENCH_BUF);
		p[0] = p[0];
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("memcpy", ft_ms, lc_ms);
}

static void	bench_memmove(void)
{
	char		buf[BENCH_BUF];
	volatile unsigned char	*p;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	memset(buf, 'B', sizeof(buf));
	p = (volatile unsigned char *)buf;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		ft_memmove(buf + 16, buf, BENCH_BUF - 16);
		p[0] = p[0];
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		memmove(buf + 16, buf, BENCH_BUF - 16);
		p[0] = p[0];
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("memmove", ft_ms, lc_ms);
}

static void	bench_memcmp(void)
{
	char		a[BENCH_BUF];
	char		b[BENCH_BUF];
	volatile int	sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	memset(a, 'X', sizeof(a));
	memset(b, 'X', sizeof(b));
	a[BENCH_BUF - 1] = 'Y';
	b[BENCH_BUF - 1] = 'Z';
	sink = 0;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		sink += ft_memcmp(a, b, BENCH_BUF);
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		sink += memcmp(a, b, BENCH_BUF);
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("memcmp", ft_ms, lc_ms);
	(void)sink;
}

static void	bench_strchr(void)
{
	const char	*s;
	volatile char	*sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	sink = NULL;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 20)
	{
		sink = ft_strchr(s, '9');
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 20)
	{
		sink = strchr(s, '9');
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("strchr", ft_ms, lc_ms);
	(void)sink;
}

static void	bench_strncmp(void)
{
	const char	*a = "libft performance comparison string AAAAAAAAAA";
	const char	*b = "libft performance comparison string AAAAAAAAAB";
	volatile int	sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	sink = 0;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 20)
	{
		sink += ft_strncmp(a, b, 48);
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 20)
	{
		sink += strncmp(a, b, 48);
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("strncmp", ft_ms, lc_ms);
	(void)sink;
}

static void	bench_atoi(void)
{
	const char	*s = "   -2147483648";
	volatile int	sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	sink = 0;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 10)
	{
		sink += ft_atoi(s);
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 10)
	{
		sink += atoi(s);
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("atoi", ft_ms, lc_ms);
	(void)sink;
}

static void	bench_strdup(void)
{
	const char	*s = "duplicate this moderately long string for the benchmark!";
	char		*p;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS / 2)
	{
		p = ft_strdup(s);
		free(p);
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS / 2)
	{
		p = strdup(s);
		free(p);
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("strdup", ft_ms, lc_ms);
}

static void	bench_strlcpy(void)
{
	char		dst[128];
	const char	*src = "strlcpy benchmark payload with enough bytes";
	volatile size_t	sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;

	sink = 0;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 10)
	{
		sink += ft_strlcpy(dst, src, sizeof(dst));
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS * 10)
	{
		sink += strlcpy(dst, src, sizeof(dst));
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("strlcpy", ft_ms, lc_ms);
	(void)sink;
}

static void	bench_ctype(void)
{
	volatile int	sink;
	double		t0;
	double		t1;
	double		ft_ms;
	double		lc_ms;
	int			i;
	int			c;

	sink = 0;
	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		c = 0;
		while (c < 128)
		{
			sink += ft_isalpha(c) + ft_isdigit(c) + ft_isalnum(c)
				+ ft_isascii(c) + ft_isprint(c)
				+ ft_toupper(c) + ft_tolower(c);
			c++;
		}
		i++;
	}
	t1 = now_sec();
	ft_ms = (t1 - t0) * 1000.0;

	t0 = now_sec();
	i = 0;
	while (i < BENCH_ITERS)
	{
		c = 0;
		while (c < 128)
		{
			sink += isalpha(c) + isdigit(c) + isalnum(c)
				+ isascii(c) + isprint(c)
				+ toupper(c) + tolower(c);
			c++;
		}
		i++;
	}
	t1 = now_sec();
	lc_ms = (t1 - t0) * 1000.0;
	print_bench("ctype*", ft_ms, lc_ms);
	(void)sink;
}

void	test_bench(void)
{
	printf(C_BOLD C_CYAN "\n== libc performance comparison ==" C_RESET "\n");
	printf("  (informational — does not fail the suite)\n");
	printf("  iters≈%d  buf=%d bytes\n", BENCH_ITERS, BENCH_BUF);
	bench_strlen();
	bench_memset();
	bench_memcpy();
	bench_memmove();
	bench_memcmp();
	bench_strchr();
	bench_strncmp();
	bench_atoi();
	bench_strdup();
	bench_strlcpy();
	bench_ctype();
	printf(C_GREEN "  OK" C_RESET " benchmarks complete\n");
}
