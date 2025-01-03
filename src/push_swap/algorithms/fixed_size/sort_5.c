/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:10:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 15:13:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	sort_for_5(
	t_ps_context *context
)
{
	int		min_index;
	int		i;
	int		j;
	t_list	*current;

	j = 0;
	while (j++ < 2)
	{
		min_index = 0;
		i = 0;
		current = context->a;
		while (current)
		{
			if (*(int *)(current->content) < *(int *)(context->a->content))
				min_index = i;
			current = current->next;
			i++;
		}
		while (min_index-- > 0)
			p_ra(context);
		p_pb(context);
	}
	sort_for_3(context);
	p_pa(context);
	p_pa(context);
}
