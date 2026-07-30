/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_memset(void)
{
	char	a[32];
	char	b[32];
	void	*ret;

	SUITE_BEGIN("ft_memset");
	memset(a, 0xAB, sizeof(a));
	memset(b, 0xAB, sizeof(b));
	ret = ft_memset(a, 'X', 10);
	memset(b, 'X', 10);
	ASSERT_EQ_PTR(ret, a);
	ASSERT_EQ_MEM(a, b, sizeof(a));
	ret = ft_memset(a, 0, 0);
	ASSERT_EQ_PTR(ret, a);
	ASSERT_EQ_MEM(a, b, sizeof(a));
	ft_memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	ASSERT_EQ_MEM(a, b, sizeof(a));
	SUITE_END("ft_memset");
}

static void	test_bzero(void)
{
	char	a[16];
	char	b[16];

	SUITE_BEGIN("ft_bzero");
	memset(a, 0xFF, sizeof(a));
	memset(b, 0xFF, sizeof(b));
	ft_bzero(a, 8);
	bzero(b, 8);
	ASSERT_EQ_MEM(a, b, sizeof(a));
	ft_bzero(a, 0);
	ASSERT_EQ_MEM(a, b, sizeof(a));
	ft_bzero(a, sizeof(a));
	bzero(b, sizeof(b));
	ASSERT_EQ_MEM(a, b, sizeof(a));
	SUITE_END("ft_bzero");
}

static void	test_memcpy(void)
{
	char		src[] = "Hello, libft!";
	char		dst1[32];
	char		dst2[32];
	void		*ret;
	char		overlap_src[16];

	SUITE_BEGIN("ft_memcpy");
	memset(dst1, 0, sizeof(dst1));
	memset(dst2, 0, sizeof(dst2));
	ret = ft_memcpy(dst1, src, strlen(src) + 1);
	memcpy(dst2, src, strlen(src) + 1);
	ASSERT_EQ_PTR(ret, dst1);
	ASSERT_EQ_STR(dst1, dst2);
	ASSERT_EQ_PTR(ft_memcpy(NULL, NULL, 0), NULL);
	/* n == 0 should not touch buffers */
	memset(dst1, 'A', sizeof(dst1));
	memset(dst2, 'A', sizeof(dst2));
	ft_memcpy(dst1, src, 0);
	ASSERT_EQ_MEM(dst1, dst2, sizeof(dst1));
	/* partial copy */
	memset(dst1, 0, sizeof(dst1));
	memset(dst2, 0, sizeof(dst2));
	ft_memcpy(dst1, src, 5);
	memcpy(dst2, src, 5);
	ASSERT_EQ_MEM(dst1, dst2, 5);
	(void)overlap_src;
	SUITE_END("ft_memcpy");
}

static void	test_memmove(void)
{
	char	buf1[32];
	char	buf2[32];
	void	*ret;

	SUITE_BEGIN("ft_memmove");
	/* non-overlapping */
	strcpy(buf1, "0123456789");
	strcpy(buf2, "0123456789");
	ret = ft_memmove(buf1 + 5, buf1, 5);
	memmove(buf2 + 5, buf2, 5);
	ASSERT_EQ_PTR(ret, buf1 + 5);
	ASSERT_EQ_MEM(buf1, buf2, 11);

	/* overlapping forward (dst > src) */
	strcpy(buf1, "abcdefghij");
	strcpy(buf2, "abcdefghij");
	ft_memmove(buf1 + 2, buf1, 8);
	memmove(buf2 + 2, buf2, 8);
	ASSERT_EQ_MEM(buf1, buf2, 11);

	/* overlapping backward (dst < src) */
	strcpy(buf1, "abcdefghij");
	strcpy(buf2, "abcdefghij");
	ft_memmove(buf1, buf1 + 2, 8);
	memmove(buf2, buf2 + 2, 8);
	ASSERT_EQ_MEM(buf1, buf2, 11);

	ASSERT_EQ_PTR(ft_memmove(NULL, NULL, 0), NULL);
	SUITE_END("ft_memmove");
}

static void	test_memchr(void)
{
	const char	*s = "Hello World";
	void		*r1;
	void		*r2;

	SUITE_BEGIN("ft_memchr");
	r1 = ft_memchr(s, 'W', 11);
	r2 = memchr(s, 'W', 11);
	ASSERT_EQ_PTR(r1, r2);
	r1 = ft_memchr(s, 'z', 11);
	r2 = memchr(s, 'z', 11);
	ASSERT_EQ_PTR(r1, r2);
	r1 = ft_memchr(s, 'H', 0);
	r2 = memchr(s, 'H', 0);
	ASSERT_EQ_PTR(r1, r2);
	r1 = ft_memchr(s, '\0', 12);
	r2 = memchr(s, '\0', 12);
	ASSERT_EQ_PTR(r1, r2);
	/* high-bit / unsigned char */
	{
		unsigned char	buf[] = {0x00, 0x7F, 0x80, 0xFF};
		r1 = ft_memchr(buf, 0x80, 4);
		r2 = memchr(buf, 0x80, 4);
		ASSERT_EQ_PTR(r1, r2);
		r1 = ft_memchr(buf, 0xFF, 4);
		r2 = memchr(buf, 0xFF, 4);
		ASSERT_EQ_PTR(r1, r2);
	}
	SUITE_END("ft_memchr");
}

static void	test_memcmp(void)
{
	SUITE_BEGIN("ft_memcmp");
	ASSERT_EQ_INT(ft_memcmp("abc", "abc", 3), memcmp("abc", "abc", 3));
	ASSERT_EQ_INT(ft_memcmp("abc", "abd", 3) < 0,
		memcmp("abc", "abd", 3) < 0);
	ASSERT_EQ_INT(ft_memcmp("abd", "abc", 3) > 0,
		memcmp("abd", "abc", 3) > 0);
	ASSERT_EQ_INT(ft_memcmp("abc", "xyz", 0), 0);
	ASSERT_EQ_INT(ft_memcmp("ab\0c", "ab\0d", 4),
		memcmp("ab\0c", "ab\0d", 4));
	{
		unsigned char	a[] = {0x00, 0x80, 0xFF};
		unsigned char	b[] = {0x00, 0x80, 0xFE};
		ASSERT_EQ_INT(ft_memcmp(a, b, 3) > 0, memcmp(a, b, 3) > 0);
	}
	SUITE_END("ft_memcmp");
}

static void	test_calloc(void)
{
	void	*p;
	size_t	i;

	SUITE_BEGIN("ft_calloc");
	p = ft_calloc(10, sizeof(int));
	ASSERT_NOT_NULL(p);
	i = 0;
	while (i < 10 * sizeof(int))
	{
		ASSERT_EQ_INT(((unsigned char *)p)[i], 0);
		i++;
	}
	free(p);
	p = ft_calloc(0, 0);
	/* both 0 is implementation-defined; should not crash */
	free(p);
	p = ft_calloc(1, 0);
	free(p);
	p = ft_calloc(0, 1);
	free(p);
	/* overflow guard */
	p = ft_calloc((size_t)-1, (size_t)-1);
	ASSERT_NULL(p);
	SUITE_END("ft_calloc");
}

void	test_mem(void)
{
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_calloc();
}
