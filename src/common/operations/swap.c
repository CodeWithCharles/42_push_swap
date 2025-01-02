/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:51:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:32:40 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// Static prototypes

static void	_swap(
				t_list	**list
				);

// Function implementations

void	sa(
	t_ps_context	*context
)
{
	_swap(&context->a);
}

void	sb(
	t_ps_context	*context
)
{
	_swap(&context->b);
}

void	ss(
	t_ps_context	*context
)
{
	_swap(&context->a);
	_swap(&context->b);
}

// Static implementations

static void	_swap(
	t_list	**list
)
{
	t_list	*first;
	t_list	*second;
	t_list	*rest;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	rest = second->next;
	first->next = rest;
	second->next = first;
	*stack = second;
}
