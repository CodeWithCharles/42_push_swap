/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:10:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 17:16:10 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Static prototypes

static int	_find_min(
				t_ps_context *context
				);

static int	_find_position(
				t_ps_context *context,
				int value
				);

static void	_move_min_to_b(
				t_ps_context *context,
				int *a_size,
				int *b_size
				);

// Function implementations

void	sort_for_5(
	t_ps_context *context
)
{
	int	a_size;
	int	b_size;

	a_size = context->count;
	b_size = 0;
	while (a_size > 3)
		_move_min_to_b(context, &a_size, &b_size);
	sort_for_3(context);
	while (b_size > 0)
	{
		p_pa(context);
		a_size++;
		b_size--;
	}
}

// Static implementations

static int	_find_min(
	t_ps_context *context
)
{
	t_list	*current;
	int		min_value;

	current = context->a;
	if (current == NULL)
		return (-1);
	min_value = *(int *)current->content;
	current = current->next;
	while (current != NULL)
	{
		if (*(int *)current->content < min_value)
			min_value = *(int *)current->content;
		current = current->next;
	}
	return (min_value);
}

static int	_find_position(
	t_ps_context *context,
	int value
)
{
	t_list	*current;
	int		position;

	current = context->a;
	position = 0;
	while (current != NULL)
	{
		if (*(int *)current->content == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

static void	_move_min_to_b(
	t_ps_context *context,
	int *a_size,
	int *b_size
)
{
	int	min_value;
	int	min_pos;

	min_value = _find_min(context);
	min_pos = _find_position(context, min_value);
	if (min_pos == 0)
	{
		p_pb(context);
		(*a_size)--;
		(*b_size)++;
	}
	else
	{
		if (min_pos <= *a_size / 2)
		{
			while (min_pos-- > 0)
				p_ra(context);
		}
		else
		{
			while (min_pos++ <= *a_size - 1)
				p_rra(context);
		}
		p_pb(context);
		(*a_size)--;
		(*b_size)++;
	}
}
