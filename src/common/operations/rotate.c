/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:57:53 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:32:31 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// Static prototypes

static void	_rotate(
				t_list	**stack
				);

// Function implementations

void	ra(
	t_ps_context	*context
)
{
	_rotate(&context->a);
}

void	rb(
	t_ps_context	*context
)
{
	_rotate(&context->b);
}

void	rr(
	t_ps_context	*context
)
{
	_rotate(&context->a);
	_rotate(&context->b);
}

// Static implementations

static void	_rotate(
	t_list	**stack
)
{
	t_list	*head;

	if (*stack == NULL)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
	ft_lstadd_back(stack, head);
}
