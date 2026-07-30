/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_substr(void)
{
	char	*r;

	SUITE_BEGIN("ft_substr");
	r = ft_substr("Hello World", 0, 5);
	ASSERT_EQ_STR(r, "Hello");
	free(r);
	r = ft_substr("Hello World", 6, 5);
	ASSERT_EQ_STR(r, "World");
	free(r);
	r = ft_substr("Hello", 2, 100);
	ASSERT_EQ_STR(r, "llo");
	free(r);
	r = ft_substr("Hello", 10, 5);
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_substr("Hello", 0, 0);
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_substr("", 0, 5);
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_substr(NULL, 0, 5);
	ASSERT_NULL(r);
	SUITE_END("ft_substr");
}

static void	test_strjoin(void)
{
	char	*r;

	SUITE_BEGIN("ft_strjoin");
	r = ft_strjoin("Hello", " World");
	ASSERT_EQ_STR(r, "Hello World");
	free(r);
	r = ft_strjoin("", "World");
	ASSERT_EQ_STR(r, "World");
	free(r);
	r = ft_strjoin("Hello", "");
	ASSERT_EQ_STR(r, "Hello");
	free(r);
	r = ft_strjoin("", "");
	ASSERT_EQ_STR(r, "");
	free(r);
	SUITE_END("ft_strjoin");
}

static void	test_strtrim(void)
{
	char	*r;

	SUITE_BEGIN("ft_strtrim");
	r = ft_strtrim("  Hello  ", " ");
	ASSERT_EQ_STR(r, "Hello");
	free(r);
	r = ft_strtrim("xxHelloWorldxx", "x");
	ASSERT_EQ_STR(r, "HelloWorld");
	free(r);
	r = ft_strtrim("ababa", "ab");
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_strtrim("Hello", "xyz");
	ASSERT_EQ_STR(r, "Hello");
	free(r);
	r = ft_strtrim("", " ");
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_strtrim("   ", " ");
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_strtrim("\t\n Hello \n\t", " \t\n");
	ASSERT_EQ_STR(r, "Hello");
	free(r);
	r = ft_strtrim(NULL, " ");
	ASSERT_NULL(r);
	r = ft_strtrim("hi", NULL);
	ASSERT_NULL(r);
	SUITE_END("ft_strtrim");
}

static void	free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	test_split(void)
{
	char	**r;

	SUITE_BEGIN("ft_split");
	r = ft_split("hello world foo", ' ');
	ASSERT_NOT_NULL(r);
	ASSERT_EQ_STR(r[0], "hello");
	ASSERT_EQ_STR(r[1], "world");
	ASSERT_EQ_STR(r[2], "foo");
	ASSERT_NULL(r[3]);
	free_split(r);

	r = ft_split("  hello   world  ", ' ');
	ASSERT_NOT_NULL(r);
	ASSERT_EQ_STR(r[0], "hello");
	ASSERT_EQ_STR(r[1], "world");
	ASSERT_NULL(r[2]);
	free_split(r);

	r = ft_split("lorem ipsum dolor", ' ');
	ASSERT_NOT_NULL(r);
	ASSERT_EQ_STR(r[0], "lorem");
	ASSERT_EQ_STR(r[1], "ipsum");
	ASSERT_EQ_STR(r[2], "dolor");
	ASSERT_NULL(r[3]);
	free_split(r);

	r = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	ASSERT_NOT_NULL(r);
	ASSERT_EQ_STR(r[0], "1");
	ASSERT_EQ_STR(r[1], "2a,");
	ASSERT_EQ_STR(r[2], "3");
	ASSERT_EQ_STR(r[3], "--h");
	ASSERT_NULL(r[4]);
	free_split(r);

	r = ft_split("", ' ');
	ASSERT_NOT_NULL(r);
	ASSERT_NULL(r[0]);
	free_split(r);

	r = ft_split("   ", ' ');
	ASSERT_NOT_NULL(r);
	ASSERT_NULL(r[0]);
	free_split(r);

	r = ft_split("nosplit", ' ');
	ASSERT_NOT_NULL(r);
	ASSERT_EQ_STR(r[0], "nosplit");
	ASSERT_NULL(r[1]);
	free_split(r);

	r = ft_split(NULL, ' ');
	ASSERT_NULL(r);
	SUITE_END("ft_split");
}

static void	test_itoa(void)
{
	char	*r;

	SUITE_BEGIN("ft_itoa");
	r = ft_itoa(0);
	ASSERT_EQ_STR(r, "0");
	free(r);
	r = ft_itoa(42);
	ASSERT_EQ_STR(r, "42");
	free(r);
	r = ft_itoa(-42);
	ASSERT_EQ_STR(r, "-42");
	free(r);
	r = ft_itoa(2147483647);
	ASSERT_EQ_STR(r, "2147483647");
	free(r);
	r = ft_itoa(-2147483648);
	ASSERT_EQ_STR(r, "-2147483648");
	free(r);
	r = ft_itoa(1);
	ASSERT_EQ_STR(r, "1");
	free(r);
	r = ft_itoa(-1);
	ASSERT_EQ_STR(r, "-1");
	free(r);
	r = ft_itoa(100);
	ASSERT_EQ_STR(r, "100");
	free(r);
	SUITE_END("ft_itoa");
}

static char	mapi_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return ((char)(c - 32));
	return (c);
}

static char	mapi_index(unsigned int i, char c)
{
	return ((char)(c + (int)i));
}

static void	test_strmapi(void)
{
	char	*r;

	SUITE_BEGIN("ft_strmapi");
	r = ft_strmapi("hello", mapi_upper);
	ASSERT_EQ_STR(r, "HELLO");
	free(r);
	r = ft_strmapi("abc", mapi_index);
	ASSERT_EQ_STR(r, "ace");
	free(r);
	r = ft_strmapi("", mapi_upper);
	ASSERT_EQ_STR(r, "");
	free(r);
	r = ft_strmapi(NULL, mapi_upper);
	ASSERT_NULL(r);
	r = ft_strmapi("hi", NULL);
	ASSERT_NULL(r);
	SUITE_END("ft_strmapi");
}

static void	iteri_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = (char)(*c - 32);
}

static void	iteri_add_index(unsigned int i, char *c)
{
	*c = (char)(*c + (int)i);
}

static void	test_striteri(void)
{
	char	s[16];

	SUITE_BEGIN("ft_striteri");
	strcpy(s, "hello");
	ft_striteri(s, iteri_upper);
	ASSERT_EQ_STR(s, "HELLO");
	strcpy(s, "abc");
	ft_striteri(s, iteri_add_index);
	ASSERT_EQ_STR(s, "ace");
	strcpy(s, "");
	ft_striteri(s, iteri_upper);
	ASSERT_EQ_STR(s, "");
	ft_striteri(NULL, iteri_upper);
	ft_striteri(s, NULL);
	SUITE_END("ft_striteri");
}

void	test_part2(void)
{
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
}
