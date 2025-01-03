/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:54:08 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 13:55:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	p_ra(
	t_ps_context *context
)
{
	ft_putstr_fd("ra\n", 1);
	ra(context);
}

void	p_rb(
	t_ps_context *context
)
{
	ft_putstr_fd("rb\n", 1);
	rb(context);
}

void	p_rr(
	t_ps_context *context
)
{
	ft_putstr_fd("rr\n", 1);
	rr(context);
}
