/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	*read_file_all(const char *path)
{
	int		fd;
	char	buf[4096];
	ssize_t	n;
	char	*out;
	size_t	len;
	size_t	cap;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	out = NULL;
	len = 0;
	cap = 0;
	while ((n = read(fd, buf, sizeof(buf))) > 0)
	{
		if (len + (size_t)n + 1 > cap)
		{
			cap = (cap == 0) ? 4096 : cap * 2;
			while (cap < len + (size_t)n + 1)
				cap *= 2;
			tmp = realloc(out, cap);
			if (!tmp)
			{
				free(out);
				close(fd);
				return (NULL);
			}
			out = tmp;
		}
		memcpy(out + len, buf, (size_t)n);
		len += (size_t)n;
	}
	close(fd);
	if (!out)
	{
		out = malloc(1);
		if (!out)
			return (NULL);
		out[0] = '\0';
		return (out);
	}
	out[len] = '\0';
	return (out);
}

static int	make_tmp(char *path, size_t path_sz)
{
	int	fd;

	snprintf(path, path_sz, "/tmp/libft_test_XXXXXX");
	fd = mkstemp(path);
	return (fd);
}

static void	test_putchar_fd(void)
{
	char	path[64];
	char	*content;
	int		fd;

	SUITE_BEGIN("ft_putchar_fd");
	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putchar_fd('A', fd);
	ft_putchar_fd('Z', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "AZ\n");
	free(content);
	unlink(path);
	SUITE_END("ft_putchar_fd");
}

static void	test_putstr_fd(void)
{
	char	path[64];
	char	*content;
	int		fd;

	SUITE_BEGIN("ft_putstr_fd");
	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putstr_fd("Hello libft", fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "Hello libft");
	free(content);
	unlink(path);

	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putstr_fd("", fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "");
	free(content);
	unlink(path);

	/* NULL should not crash (common 42 expectation: no-op) */
	ft_putstr_fd(NULL, 1);
	SUITE_END("ft_putstr_fd");
}

static void	test_putendl_fd(void)
{
	char	path[64];
	char	*content;
	int		fd;

	SUITE_BEGIN("ft_putendl_fd");
	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putendl_fd("line", fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "line\n");
	free(content);
	unlink(path);

	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putendl_fd("", fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "\n");
	free(content);
	unlink(path);
	SUITE_END("ft_putendl_fd");
}

static void	test_putnbr_fd(void)
{
	char	path[64];
	char	*content;
	int		fd;

	SUITE_BEGIN("ft_putnbr_fd");
	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putnbr_fd(0, fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "0");
	free(content);
	unlink(path);

	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putnbr_fd(42, fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "42");
	free(content);
	unlink(path);

	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putnbr_fd(-42, fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "-42");
	free(content);
	unlink(path);

	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putnbr_fd(2147483647, fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "2147483647");
	free(content);
	unlink(path);

	fd = make_tmp(path, sizeof(path));
	ASSERT_TRUE(fd >= 0);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	content = read_file_all(path);
	ASSERT_EQ_STR(content, "-2147483648");
	free(content);
	unlink(path);
	SUITE_END("ft_putnbr_fd");
}

void	test_fd(void)
{
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
}
