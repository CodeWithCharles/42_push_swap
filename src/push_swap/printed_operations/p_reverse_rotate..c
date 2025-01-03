/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_reverse_rotate..c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:48:10 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 13:53:55 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	p_rra(
	t_ps_context *context
)
{
	ft_putstr_fd("rra\n", 1);
	rra(context);
}

void	p_rrb(
	t_ps_context *context
)
{
	ft_putstr_fd("rrb\n", 1);
	rrb(context);
}

void	p_rrr(
	t_ps_context *context
)
{
	ft_putstr_fd("rrr\n", 1);
	rrr(context);
}
