/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betanco <betanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:00:00 by betanco           #+#    #+#             */
/*   Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	g_tests_run = 0;
int	g_tests_failed = 0;
int	g_suite_failed = 0;

double	now_sec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1e6);
}

int	main(void)
{
	printf(C_BOLD "\nlibft unit tests + libc performance\n" C_RESET);

	test_ctype();
	test_mem();
	test_str();
	test_part2();
	test_fd();
	test_bonus();
	test_bench();

	printf(C_BOLD "\n========================================\n" C_RESET);
	if (g_tests_failed == 0)
	{
		printf(C_GREEN C_BOLD "ALL PASSED" C_RESET
			"  (%d assertions)\n\n", g_tests_run);
		return (0);
	}
	printf(C_RED C_BOLD "%d FAILED" C_RESET " / %d assertions\n\n",
		g_tests_failed, g_tests_run);
	return (1);
}
