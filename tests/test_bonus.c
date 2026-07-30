/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	del_content(void *content)
{
	free(content);
}

static void	noop_del(void *content)
{
	(void)content;
}

static void	iter_toupper_str(void *content)
{
	char	*s;

	s = (char *)content;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = (char)(*s - 32);
		s++;
	}
}

static void	*map_dup_upper(void *content)
{
	char	*src;
	char	*dst;
	size_t	i;

	src = (char *)content;
	dst = ft_strdup(src);
	if (!dst)
		return (NULL);
	i = 0;
	while (dst[i])
	{
		if (dst[i] >= 'a' && dst[i] <= 'z')
			dst[i] = (char)(dst[i] - 32);
		i++;
	}
	return (dst);
}

static void	test_lstnew(void)
{
	t_list	*n;
	int		x;

	SUITE_BEGIN("ft_lstnew");
	x = 42;
	n = ft_lstnew(&x);
	ASSERT_NOT_NULL(n);
	ASSERT_EQ_PTR(n->content, &x);
	ASSERT_NULL(n->next);
	free(n);

	n = ft_lstnew(NULL);
	ASSERT_NOT_NULL(n);
	ASSERT_NULL(n->content);
	ASSERT_NULL(n->next);
	free(n);
	SUITE_END("ft_lstnew");
}

static void	test_lstadd_front(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;

	SUITE_BEGIN("ft_lstadd_front");
	lst = NULL;
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	ft_lstadd_front(&lst, a);
	ASSERT_EQ_PTR(lst, a);
	ft_lstadd_front(&lst, b);
	ASSERT_EQ_PTR(lst, b);
	ASSERT_EQ_PTR(lst->next, a);
	ASSERT_NULL(a->next);
	ft_lstclear(&lst, del_content);
	SUITE_END("ft_lstadd_front");
}

static void	test_lstsize_last(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	SUITE_BEGIN("ft_lstsize / ft_lstlast");
	ASSERT_EQ_INT(ft_lstsize(NULL), 0);
	ASSERT_NULL(ft_lstlast(NULL));

	a = ft_lstnew(ft_strdup("1"));
	b = ft_lstnew(ft_strdup("2"));
	c = ft_lstnew(ft_strdup("3"));
	lst = a;
	a->next = b;
	b->next = c;
	ASSERT_EQ_INT(ft_lstsize(lst), 3);
	ASSERT_EQ_PTR(ft_lstlast(lst), c);
	ASSERT_EQ_STR((char *)ft_lstlast(lst)->content, "3");
	ft_lstclear(&lst, del_content);
	SUITE_END("ft_lstsize / ft_lstlast");
}

static void	test_lstadd_back(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	SUITE_BEGIN("ft_lstadd_back");
	lst = NULL;
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	c = ft_lstnew(ft_strdup("c"));
	ft_lstadd_back(&lst, a);
	ASSERT_EQ_PTR(lst, a);
	ft_lstadd_back(&lst, b);
	ft_lstadd_back(&lst, c);
	ASSERT_EQ_PTR(lst, a);
	ASSERT_EQ_PTR(lst->next, b);
	ASSERT_EQ_PTR(lst->next->next, c);
	ASSERT_NULL(c->next);
	ASSERT_EQ_INT(ft_lstsize(lst), 3);
	ft_lstclear(&lst, del_content);
	SUITE_END("ft_lstadd_back");
}

static void	test_lstdelone(void)
{
	t_list	*n;
	char	*s;

	SUITE_BEGIN("ft_lstdelone");
	s = ft_strdup("delete me");
	n = ft_lstnew(s);
	ft_lstdelone(n, del_content);
	/* if we reach here without crash, free path works */
	ASSERT_TRUE(1);
	ft_lstdelone(NULL, del_content);
	SUITE_END("ft_lstdelone");
}

static void	test_lstclear(void)
{
	t_list	*lst;

	SUITE_BEGIN("ft_lstclear");
	lst = ft_lstnew(ft_strdup("1"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("2")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("3")));
	ft_lstclear(&lst, del_content);
	ASSERT_NULL(lst);
	ft_lstclear(&lst, del_content);
	SUITE_END("ft_lstclear");
}

static void	test_lstiter(void)
{
	t_list	*lst;

	SUITE_BEGIN("ft_lstiter");
	lst = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
	ft_lstiter(lst, iter_toupper_str);
	ASSERT_EQ_STR((char *)lst->content, "HELLO");
	ASSERT_EQ_STR((char *)lst->next->content, "WORLD");
	ft_lstclear(&lst, del_content);
	ft_lstiter(NULL, iter_toupper_str);
	SUITE_END("ft_lstiter");
}

static void	test_lstmap(void)
{
	t_list	*lst;
	t_list	*mapped;

	SUITE_BEGIN("ft_lstmap");
	lst = ft_lstnew(ft_strdup("abc"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("xyz")));
	mapped = ft_lstmap(lst, map_dup_upper, del_content);
	ASSERT_NOT_NULL(mapped);
	ASSERT_EQ_STR((char *)mapped->content, "ABC");
	ASSERT_EQ_STR((char *)mapped->next->content, "XYZ");
	ASSERT_NULL(mapped->next->next);
	/* original unchanged */
	ASSERT_EQ_STR((char *)lst->content, "abc");
	ft_lstclear(&lst, del_content);
	ft_lstclear(&mapped, del_content);

	ASSERT_NULL(ft_lstmap(NULL, map_dup_upper, del_content));
	lst = ft_lstnew(ft_strdup("x"));
	ASSERT_NULL(ft_lstmap(lst, NULL, del_content));
	ASSERT_NULL(ft_lstmap(lst, map_dup_upper, NULL));
	ft_lstclear(&lst, del_content);
	(void)noop_del;
	SUITE_END("ft_lstmap");
}

void	test_bonus(void)
{
	test_lstnew();
	test_lstadd_front();
	test_lstsize_last();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();
}
