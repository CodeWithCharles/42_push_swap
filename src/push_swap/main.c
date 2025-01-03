/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:27:26 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 15:31:23 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

#include <limits.h>
#include <stdbool.h>

// Main

int	main(
	int argc,
	char **argv
)
{
	t_ps_context	*context;

	(void)argc;
	context = initialize_context((const char **)(argv + 1));
	if (context == NULL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
	initialize_operations(context);
	if (context->count < 2 || is_sorted(context->a))
		;
	else if (context->count == 2)
		sort_for_2(context);
	else if (context->count == 3)
		sort_for_3(context);
	else if (context->count == 4)
		sort_for_4(context);
	else if (context->count == 5)
		sort_for_5(context);
	else
		radix_sort(context);
	return (cleanup_context(&context), EXIT_SUCCESS);
}
