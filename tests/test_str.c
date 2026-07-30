/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strlen(void)
{
	SUITE_BEGIN("ft_strlen");
	ASSERT_EQ_SIZE(ft_strlen(""), strlen(""));
	ASSERT_EQ_SIZE(ft_strlen("a"), strlen("a"));
	ASSERT_EQ_SIZE(ft_strlen("Hello"), strlen("Hello"));
	ASSERT_EQ_SIZE(ft_strlen("Hello, World!"), strlen("Hello, World!"));
	SUITE_END("ft_strlen");
}

static void	test_strchr(void)
{
	const char	*s = "Hello World";

	SUITE_BEGIN("ft_strchr");
	ASSERT_EQ_PTR(ft_strchr(s, 'H'), strchr(s, 'H'));
	ASSERT_EQ_PTR(ft_strchr(s, 'o'), strchr(s, 'o'));
	ASSERT_EQ_PTR(ft_strchr(s, 'z'), strchr(s, 'z'));
	ASSERT_EQ_PTR(ft_strchr(s, '\0'), strchr(s, '\0'));
	ASSERT_EQ_PTR(ft_strchr(s, 'W'), strchr(s, 'W'));
	SUITE_END("ft_strchr");
}

static void	test_strrchr(void)
{
	const char	*s = "Hello World";

	SUITE_BEGIN("ft_strrchr");
	ASSERT_EQ_PTR(ft_strrchr(s, 'o'), strrchr(s, 'o'));
	ASSERT_EQ_PTR(ft_strrchr(s, 'l'), strrchr(s, 'l'));
	ASSERT_EQ_PTR(ft_strrchr(s, 'H'), strrchr(s, 'H'));
	ASSERT_EQ_PTR(ft_strrchr(s, 'z'), strrchr(s, 'z'));
	ASSERT_EQ_PTR(ft_strrchr(s, '\0'), strrchr(s, '\0'));
	SUITE_END("ft_strrchr");
}

static void	test_strncmp(void)
{
	SUITE_BEGIN("ft_strncmp");
	ASSERT_EQ_INT(ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
	ASSERT_EQ_INT(ft_strncmp("abc", "abd", 3) < 0,
		strncmp("abc", "abd", 3) < 0);
	ASSERT_EQ_INT(ft_strncmp("abc", "abc", 0), 0);
	ASSERT_EQ_INT(ft_strncmp("abc", "abcdef", 3),
		strncmp("abc", "abcdef", 3));
	ASSERT_EQ_INT(ft_strncmp("abcdef", "abc", 6) > 0,
		strncmp("abcdef", "abc", 6) > 0);
	ASSERT_EQ_INT(ft_strncmp("", "", 1), strncmp("", "", 1));
	/* unsigned char semantics */
	{
		char	a[] = {(char)0xFF, 0};
		char	b[] = {(char)0x01, 0};

		ASSERT_EQ_INT(ft_strncmp(a, b, 1) > 0, strncmp(a, b, 1) > 0);
	}
	SUITE_END("ft_strncmp");
}

static void	test_strnstr(void)
{
	const char	*hay = "Foo Bar Baz";

	SUITE_BEGIN("ft_strnstr");
	ASSERT_EQ_PTR(ft_strnstr(hay, "Bar", 11), strnstr(hay, "Bar", 11));
	ASSERT_EQ_PTR(ft_strnstr(hay, "Baz", 11), strnstr(hay, "Baz", 11));
	ASSERT_EQ_PTR(ft_strnstr(hay, "Foo", 2), strnstr(hay, "Foo", 2));
	ASSERT_EQ_PTR(ft_strnstr(hay, "Foo", 3), strnstr(hay, "Foo", 3));
	ASSERT_EQ_PTR(ft_strnstr(hay, "", 5), strnstr(hay, "", 5));
	ASSERT_EQ_PTR(ft_strnstr(hay, "xyz", 11), strnstr(hay, "xyz", 11));
	ASSERT_EQ_PTR(ft_strnstr(hay, "Bar", 4), strnstr(hay, "Bar", 4));
	ASSERT_EQ_PTR(ft_strnstr(hay, "Bar", 7), strnstr(hay, "Bar", 7));
	ASSERT_EQ_PTR(ft_strnstr("", "", 0), strnstr("", "", 0));
	ASSERT_EQ_PTR(ft_strnstr("abc", "abc", 3), strnstr("abc", "abc", 3));
	SUITE_END("ft_strnstr");
}

static void	test_strlcpy(void)
{
	char	d1[16];
	char	d2[16];
	size_t	r1;
	size_t	r2;

	SUITE_BEGIN("ft_strlcpy");
	memset(d1, 'X', sizeof(d1));
	memset(d2, 'X', sizeof(d2));
	r1 = ft_strlcpy(d1, "hello", sizeof(d1));
	r2 = strlcpy(d2, "hello", sizeof(d2));
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);

	memset(d1, 'X', sizeof(d1));
	memset(d2, 'X', sizeof(d2));
	r1 = ft_strlcpy(d1, "hello world", 6);
	r2 = strlcpy(d2, "hello world", 6);
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);

	r1 = ft_strlcpy(d1, "abc", 0);
	r2 = strlcpy(d2, "abc", 0);
	ASSERT_EQ_SIZE(r1, r2);

	memset(d1, 'X', sizeof(d1));
	memset(d2, 'X', sizeof(d2));
	r1 = ft_strlcpy(d1, "", sizeof(d1));
	r2 = strlcpy(d2, "", sizeof(d2));
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);
	SUITE_END("ft_strlcpy");
}

static void	test_strlcat(void)
{
	char	d1[32];
	char	d2[32];
	size_t	r1;
	size_t	r2;

	SUITE_BEGIN("ft_strlcat");
	strcpy(d1, "Hello");
	strcpy(d2, "Hello");
	r1 = ft_strlcat(d1, " World", sizeof(d1));
	r2 = strlcat(d2, " World", sizeof(d2));
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);

	strcpy(d1, "Hello");
	strcpy(d2, "Hello");
	r1 = ft_strlcat(d1, " World", 8);
	r2 = strlcat(d2, " World", 8);
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);

	/* dstsize <= strlen(dst) */
	strcpy(d1, "Hello");
	strcpy(d2, "Hello");
	r1 = ft_strlcat(d1, "XX", 3);
	r2 = strlcat(d2, "XX", 3);
	ASSERT_EQ_SIZE(r1, r2);

	strcpy(d1, "ab");
	strcpy(d2, "ab");
	r1 = ft_strlcat(d1, "", sizeof(d1));
	r2 = strlcat(d2, "", sizeof(d2));
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);

	strcpy(d1, "");
	strcpy(d2, "");
	r1 = ft_strlcat(d1, "hi", sizeof(d1));
	r2 = strlcat(d2, "hi", sizeof(d2));
	ASSERT_EQ_SIZE(r1, r2);
	ASSERT_EQ_STR(d1, d2);
	SUITE_END("ft_strlcat");
}

static void	test_strdup(void)
{
	char	*p1;
	char	*p2;

	SUITE_BEGIN("ft_strdup");
	p1 = ft_strdup("hello");
	p2 = strdup("hello");
	ASSERT_NOT_NULL(p1);
	ASSERT_EQ_STR(p1, p2);
	free(p1);
	free(p2);

	p1 = ft_strdup("");
	p2 = strdup("");
	ASSERT_NOT_NULL(p1);
	ASSERT_EQ_STR(p1, p2);
	free(p1);
	free(p2);
	SUITE_END("ft_strdup");
}

static void	test_atoi(void)
{
	const char	*cases[] = {
		"0", "42", "-42", "+42", "   123", "\t\n\r\v\f 456",
		"-+42", "+-42", "   -+12", "2147483647", "-2147483648",
		"  +0", "abc", "12abc34", "", "  ", "--1", "++1",
		"999999999", NULL
	};
	int			i;

	SUITE_BEGIN("ft_atoi");
	i = 0;
	while (cases[i])
	{
		ASSERT_EQ_INT(ft_atoi(cases[i]), atoi(cases[i]));
		i++;
	}
	SUITE_END("ft_atoi");
}

void	test_str(void)
{
	test_strlen();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_strnstr();
	test_strlcpy();
	test_strlcat();
	test_strdup();
	test_atoi();
}
