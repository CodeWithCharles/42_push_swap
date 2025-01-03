/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:14:18 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 15:44:41 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdbool.h>

// Static prototypes

static size_t	_bit_width(
					size_t x
					);

static size_t	_radix(
					t_ps_context *context,
					int mask,
					bool is_base_b
					);

static void		_roll_back(
					t_ps_context *context,
					bool is_base_b
					);

// Function implementations

void	radix_sort(
	t_ps_context *context
)
{
	size_t	i;
	size_t	pushed;
	size_t	iterations;
	bool	is_base_b;

	i = 0;
	is_base_b = false;
	iterations = _bit_width(context->count) + 1;
	while (i < iterations)
	{
		pushed = _radix(context, 1 << i, is_base_b);
		if (pushed >= context->count / 2)
			is_base_b ^= true;
		if (++i == iterations)
			is_base_b = false;
		_roll_back(context, is_base_b);
	}
}

// Static implementations

static size_t	_bit_width(
	size_t x
)
{
	static const size_t	size_t_size = sizeof(size_t) * 8;
	size_t				n;

	n = 0;
	while (!(x & (1UL << (size_t_size - 1))))
	{
		++n;
		x <<= 1;
	}
	return (size_t_size - n - 1);
}

static size_t	_radix(
	t_ps_context *context,
	int mask,
	bool is_base_b
)
{
	size_t	j;
	size_t	count;
	t_list	**head;
	void	(*push)(t_ps_context *);
	void	(*rotate)(t_ps_context *);

	head = &context->a;
	push = p_pb;
	rotate = p_ra;
	if (is_base_b)
	{
		head = &context->b;
		push = p_pa;
		rotate = p_rb;
	}
	count = 0;
	j = 0;
	while (j++ < context->count)
	{
		if (is_base_b ^ (((*(int *)(*head)->content) & mask) != 0))
			rotate(context);
		else
			(push(context), ++count);
	}
	return (count);
}

static void	_roll_back(
	t_ps_context *context,
	bool is_base_b
)
{
	void	(*push)(t_ps_context *);
	t_list	**head;

	push = p_pa;
	head = &context->b;
	if (is_base_b)
	{
		push = p_pb;
		head = &context->a;
	}
	while (*head)
		push(context);
}
