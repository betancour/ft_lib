/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_isalpha(void)
{
	int	c;

	SUITE_BEGIN("ft_isalpha");
	c = 0;
	while (c < 128)
	{
		ASSERT_SAME_BOOL(ft_isalpha(c), isalpha(c));
		c++;
	}
	ASSERT_EQ_INT(ft_isalpha('A'), 1);
	ASSERT_EQ_INT(ft_isalpha('z'), 1);
	ASSERT_EQ_INT(ft_isalpha('5'), 0);
	ASSERT_EQ_INT(ft_isalpha(' '), 0);
	ASSERT_EQ_INT(ft_isalpha(0), 0);
	ASSERT_EQ_INT(ft_isalpha(127), 0);
	SUITE_END("ft_isalpha");
}

static void	test_isdigit(void)
{
	int	c;

	SUITE_BEGIN("ft_isdigit");
	c = 0;
	while (c < 128)
	{
		ASSERT_SAME_BOOL(ft_isdigit(c), isdigit(c));
		c++;
	}
	ASSERT_EQ_INT(ft_isdigit('0'), 1);
	ASSERT_EQ_INT(ft_isdigit('9'), 1);
	ASSERT_EQ_INT(ft_isdigit('a'), 0);
	ASSERT_EQ_INT(ft_isdigit('/'), 0);
	ASSERT_EQ_INT(ft_isdigit(':'), 0);
	SUITE_END("ft_isdigit");
}

static void	test_isalnum(void)
{
	int	c;

	SUITE_BEGIN("ft_isalnum");
	c = 0;
	while (c < 128)
	{
		ASSERT_SAME_BOOL(ft_isalnum(c), isalnum(c));
		c++;
	}
	ASSERT_EQ_INT(ft_isalnum('A'), 1);
	ASSERT_EQ_INT(ft_isalnum('9'), 1);
	ASSERT_EQ_INT(ft_isalnum('!'), 0);
	SUITE_END("ft_isalnum");
}

static void	test_isascii(void)
{
	int	c;

	SUITE_BEGIN("ft_isascii");
	c = -1;
	while (c < 256)
	{
		ASSERT_SAME_BOOL(ft_isascii(c), isascii(c));
		c++;
	}
	ASSERT_EQ_INT(ft_isascii(0), 1);
	ASSERT_EQ_INT(ft_isascii(127), 1);
	ASSERT_EQ_INT(ft_isascii(128), 0);
	ASSERT_EQ_INT(ft_isascii(-1), 0);
	SUITE_END("ft_isascii");
}

static void	test_isprint(void)
{
	int	c;

	SUITE_BEGIN("ft_isprint");
	c = 0;
	while (c < 128)
	{
		ASSERT_SAME_BOOL(ft_isprint(c), isprint(c));
		c++;
	}
	ASSERT_EQ_INT(ft_isprint(' '), 1);
	ASSERT_EQ_INT(ft_isprint('~'), 1);
	ASSERT_EQ_INT(ft_isprint(31), 0);
	ASSERT_EQ_INT(ft_isprint(127), 0);
	SUITE_END("ft_isprint");
}

static void	test_toupper(void)
{
	int	c;

	SUITE_BEGIN("ft_toupper");
	c = 0;
	while (c < 128)
	{
		ASSERT_EQ_INT(ft_toupper(c), toupper(c));
		c++;
	}
	ASSERT_EQ_INT(ft_toupper('a'), 'A');
	ASSERT_EQ_INT(ft_toupper('Z'), 'Z');
	ASSERT_EQ_INT(ft_toupper('5'), '5');
	SUITE_END("ft_toupper");
}

static void	test_tolower(void)
{
	int	c;

	SUITE_BEGIN("ft_tolower");
	c = 0;
	while (c < 128)
	{
		ASSERT_EQ_INT(ft_tolower(c), tolower(c));
		c++;
	}
	ASSERT_EQ_INT(ft_tolower('A'), 'a');
	ASSERT_EQ_INT(ft_tolower('z'), 'z');
	ASSERT_EQ_INT(ft_tolower('5'), '5');
	SUITE_END("ft_tolower");
}

void	test_ctype(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
}
