/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:09:10 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 14:10:31 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	sort_for_2(
	t_ps_context *context
)
{
	int	first;
	int	second;

	first = *(int *)context->a->content;
	second = *(int *)context->a->next->content;
	if (first > second)
		p_sa(context);
}
