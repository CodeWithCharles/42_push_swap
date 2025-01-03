/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:10:37 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 14:15:13 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	sort_for_3(
	t_ps_context *context
)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)context->a->content;
	second = *(int *)context->a->next->content;
	third = *(int *)context->a->next->next->content;
	if (first < second && first < third && second > third)
		(p_sa(context), p_ra(context));
	else if (first < second && first > third && second > third)
		(p_rra(context));
	else if (first > second && first < third && second < third)
		(p_sa(context));
	else if (first > second && first > third && second < third)
		(p_ra(context));
	else if (first > second && first > third && second > third)
		(p_ra(context), p_sa(context));
}
