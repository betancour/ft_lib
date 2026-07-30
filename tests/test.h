/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include <sys/time.h>
# include <errno.h>

/* ---------- globals ---------- */
extern int	g_tests_run;
extern int	g_tests_failed;
extern int	g_suite_failed;

/* ---------- colors ---------- */
# define C_RESET	"\033[0m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_YELLOW	"\033[33m"
# define C_CYAN		"\033[36m"
# define C_BOLD		"\033[1m"

/* ---------- assertions ---------- */
# define ASSERT_TRUE(cond) do { \
	g_tests_run++; \
	if (!(cond)) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: ASSERT_TRUE(%s)\n", \
			__FILE__, __LINE__, #cond); \
	} \
} while (0)

# define ASSERT_EQ_INT(a, b) do { \
	long long _a = (long long)(a); \
	long long _b = (long long)(b); \
	g_tests_run++; \
	if (_a != _b) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: %s == %s  (%lld != %lld)\n", \
			__FILE__, __LINE__, #a, #b, _a, _b); \
	} \
} while (0)

# define ASSERT_EQ_SIZE(a, b) do { \
	size_t _a = (size_t)(a); \
	size_t _b = (size_t)(b); \
	g_tests_run++; \
	if (_a != _b) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: %s == %s  (%zu != %zu)\n", \
			__FILE__, __LINE__, #a, #b, _a, _b); \
	} \
} while (0)

# define ASSERT_EQ_PTR(a, b) do { \
	const void *_a = (const void *)(a); \
	const void *_b = (const void *)(b); \
	g_tests_run++; \
	if (_a != _b) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: %s == %s  (%p != %p)\n", \
			__FILE__, __LINE__, #a, #b, _a, _b); \
	} \
} while (0)

# define ASSERT_EQ_STR(a, b) do { \
	const char *_a = (const char *)(a); \
	const char *_b = (const char *)(b); \
	g_tests_run++; \
	if ((_a == NULL && _b != NULL) || (_a != NULL && _b == NULL) \
		|| (_a && _b && strcmp(_a, _b) != 0)) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: %s == %s  (\"%s\" != \"%s\")\n", \
			__FILE__, __LINE__, #a, #b, \
			_a ? _a : "(null)", _b ? _b : "(null)"); \
	} \
} while (0)

# define ASSERT_EQ_MEM(a, b, n) do { \
	g_tests_run++; \
	if (memcmp((a), (b), (n)) != 0) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: memcmp(%s, %s, %zu) != 0\n", \
			__FILE__, __LINE__, #a, #b, (size_t)(n)); \
	} \
} while (0)

# define ASSERT_NULL(p) ASSERT_EQ_PTR((p), NULL)
# define ASSERT_NOT_NULL(p) do { \
	g_tests_run++; \
	if ((p) == NULL) { \
		g_tests_failed++; \
		g_suite_failed++; \
		printf(C_RED "  FAIL" C_RESET " %s:%d: %s is NULL\n", \
			__FILE__, __LINE__, #p); \
	} \
} while (0)

/* truthiness: libc ctype returns non-zero, ft_* returns 0/1 */
# define ASSERT_SAME_BOOL(a, b) ASSERT_EQ_INT(!!(a), !!(b))

/* ---------- suite helpers ---------- */
# define SUITE_BEGIN(name) do { \
	g_suite_failed = 0; \
	printf(C_BOLD C_CYAN "\n== %s ==" C_RESET "\n", (name)); \
} while (0)

# define SUITE_END(name) do { \
	if (g_suite_failed == 0) \
		printf(C_GREEN "  OK" C_RESET " %s\n", (name)); \
	else \
		printf(C_RED "  %d failed in %s" C_RESET "\n", g_suite_failed, (name)); \
} while (0)

/* ---------- test entry points ---------- */
void	test_ctype(void);
void	test_mem(void);
void	test_str(void);
void	test_part2(void);
void	test_fd(void);
void	test_bonus(void);
void	test_bench(void);

/* ---------- timing ---------- */
double	now_sec(void);

#endif
