/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:11:54 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:32:26 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// Static prototypes

static void	_reverse_rotate(
				t_list	**stack
				);

// Function implementations

void	rra(
	t_ps_context	*context
)
{
	_reverse_rotate(&context->a);
}

void	rrb(
	t_ps_context	*context
)
{
	_reverse_rotate(&context->b);
}

void	rrr(
	t_ps_context	*context
)
{
	_reverse_rotate(&context->a);
	_reverse_rotate(&context->b);
}

// Static implementations

static void	_reverse_rotate(
	t_list	**stack
)
{
	t_list	**itr;

	if (*stack == NULL)
		return ;
	itr = stack;
	while ((*itr)->next)
		itr = &(*itr)->next;
	(*itr)->next = *stack;
	*stack = *itr;
	*itr = NULL;
}
